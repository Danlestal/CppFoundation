#include "PhysicsSystem.hpp"
#include <list>
#include <algorithm>
#include "../components/BoundingSquareComponent.hpp"
#include "../components/BidimensionalComponent.hpp"
#include "../events/ActorCollidesEventData.hpp"
#include "../events/UpdateActorPositionEventData.hpp"
#include "../events/AddActorEventData.hpp"
#include "../events/DestroyActorEventData.hpp"
#include "../events/ActorQueryEventData.hpp"
#include "../events/AnswerToActorQueryEventData.hpp"


PhysicsSystem::PhysicsSystem(Scene* scene) {
    mScene = scene;
    mEventManager = scene->getEventManager();

    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                &PhysicsSystem::updatePosition),
                                "UpdateActorPositionEventDataType");

    mEventManager->addListener(fastdelegate::MakeDelegate(
                                    this,
                                    &PhysicsSystem::addActor),
                                    "AddActorEventDataType");

    mEventManager->addListener(fastdelegate::MakeDelegate(
                                this,
                                &PhysicsSystem::removeActor),
                                "DestroyActorEventDataType");

    mEventManager->addListener(fastdelegate::MakeDelegate(
                            this,
                            &PhysicsSystem::answer2dQuery),
                            "ActorQueryEventDataType");
}

PhysicsSystem::~PhysicsSystem() {
    mEventManager->removeListener(fastdelegate::MakeDelegate(this,
                                &PhysicsSystem::updatePosition),
                                "UpdateActorPositionEventDataType");

    mEventManager->removeListener(fastdelegate::MakeDelegate(
                                    this,
                                    &PhysicsSystem::addActor),
                                    "AddActorEventDataType");

    mEventManager->removeListener(fastdelegate::MakeDelegate(
                                this,
                                &PhysicsSystem::removeActor),
                                "DestroyActorEventDataType");
                                
    mEventManager->removeListener(fastdelegate::MakeDelegate(
                        this,
                        &PhysicsSystem::answer2dQuery),
                        "ActorQueryEventDataType");
}


void PhysicsSystem::checkActorPhysics(ActorPhysics* toCheck) {
    for ( int i = 0; i< mAxisList.size(); ++i ) {
        ActorPhysics* other = mAxisList.at(i);
        if (other == toCheck)
            continue;
        if (collides(toCheck->box, other->box)) {
            bool collidesWithBoundary = toCheck->isBoundary || other->isBoundary;
            mEventManager->queueEvent(new ActorCollidesEventData( toCheck->actorId,
                                                                    other->actorId,
                                                                    toCheck->lastMovement,
                                                                    collidesWithBoundary));
        }
    }
}

static bool compareXAxis(const ActorPhysics* first, const ActorPhysics* second) {
    return (first->box.min.x < second->box.min.x);
}

void PhysicsSystem::createAndAddActorIfNeeded(Actor* actor) {
    if (actor->hasComponent("BidimensionalComponent") && actor->hasComponent("BoundingSquareComponent")) {
            std::vector<ActorPhysics*> actorPhysics = createActorPhysics(actor);
            mAxisList.insert(mAxisList.end(),
                                actorPhysics.begin(),
                                actorPhysics.end());
    }
}

std::vector<ActorPhysics*> PhysicsSystem::createActorPhysics(Actor* actor) {
    BidimensionalComponent* positionComponent = reinterpret_cast<BidimensionalComponent*>
                (actor->getComponents("BidimensionalComponent")[0]);


    std::vector<ActorPhysics*> result;
    std::vector<Component*> boundingComponents = actor->getComponents("BoundingSquareComponent");
    for (auto it = boundingComponents.begin(); it != boundingComponents.end(); ++it) {
        BoundingSquareComponent* squareComponent = reinterpret_cast<BoundingSquareComponent*>(*it);
        AABB box = AABB();
        box.min = positionComponent->getPos();
        box.max = box.min + squareComponent->getDimensions();
        ActorPhysics *phys = new ActorPhysics();
        phys->box = box;
        phys->actorId = actor->getId();
        phys->lastMovement = Vector2D();
        phys->isBoundary = squareComponent->isBoundary();
        result.push_back(phys);
    }

    return result;
}

AABB PhysicsSystem::createMockAABBBox(Vector2D position) {
    AABB box = AABB();
    box.min = position;
    box.max = position + Vector2D(5, 5);  // The mock box has 5x5 pixels
    return box;
}

bool PhysicsSystem::collides(AABB firstBox, AABB secondBox) {
    return (firstBox.min.x < secondBox.max.x &&
        firstBox.max.x > secondBox.min.x &&
        firstBox.min.y < secondBox.max.y &&
        firstBox.max.y > secondBox.min.y);
}

ActorPhysics* PhysicsSystem::findActor(long id) {
    for (auto it = mAxisList.begin(); it != mAxisList.end(); ++it) {
        ActorPhysics* actor = (*it);
        if (actor->actorId == id) {
            return actor;
        }
    }
    return NULL;
}

int PhysicsSystem::findActorIndex(long id) {
    int index = 0;
    if (mAxisList.size() == 0) {
        return -1;
    }

    for (auto it = mAxisList.begin(); it != mAxisList.end(); ++it) {
        ActorPhysics* actor = (*it);
        if (actor != nullptr && actor->actorId == id) {
            return index;
        }
        index++;
    }
    return -1;
}

void PhysicsSystem::updatePosition(IEventData* pEventData) {
    UpdateActorPositionEventData* moveEvent = reinterpret_cast<UpdateActorPositionEventData*>(pEventData);
    ActorPhysics* physics = findActor(moveEvent->getActorId());
    if (physics == nullptr)
        return;

    Vector2D lastMovement = moveEvent->getDelta();
    physics->lastMovement = lastMovement;
    physics->box += lastMovement;
    checkActorPhysics(physics);
}

void PhysicsSystem::addActor(IEventData* newActorAddedEvent) {
    AddActorEventData* addEvent = reinterpret_cast<AddActorEventData*>(newActorAddedEvent);
    Actor* actorToAdd = mScene->getActor(addEvent->getActorId());
    createAndAddActorIfNeeded(actorToAdd);
}

void PhysicsSystem::removeActorById(long id) {
    int index = findActorIndex(id);
    if (index != -1) {
        mAxisList.erase(mAxisList.begin() + index);
    }
}

void PhysicsSystem::removeActor(IEventData* removeActorEvent) {
    DestroyActorEventData* removeEvent = reinterpret_cast<DestroyActorEventData*>(removeActorEvent);
    removeActorById(removeEvent->getActorId());
}


void PhysicsSystem::answer2dQuery(IEventData* pEventData) {
    ActorQueryEventData* queryEvent = reinterpret_cast<ActorQueryEventData*>(pEventData);
    AABB mockBox = createMockAABBBox(queryEvent->getPositionToQuery());
    std::vector<long> actorsThatCollide;
    for ( int i = 0; i< mAxisList.size(); ++i ) {
        ActorPhysics* actorPhysics = mAxisList.at(i);
        if (collides(mockBox, actorPhysics->box)) {
            actorsThatCollide.push_back(actorPhysics->actorId);
        }
    }

    mEventManager->queueEvent(new AnswerToActorQueryEventData(actorsThatCollide));
}