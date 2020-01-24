#include "PhysicsSystem.hpp"
#include <list>
#include <algorithm>
#include "../components/BoundingSquareComponent.hpp"
#include "../components/BidimensionalComponent.hpp"
#include "../events/ActorCollidesEventData.hpp"


PhysicsSystem::PhysicsSystem(EventManager* eventManager) {
    mEventManager = eventManager;
}

void PhysicsSystem::update() {
    std::sort(mAxisList.begin(), mAxisList.end(), compareYAxis);
    for ( int i = 1; i< mAxisList.size(); ++i ) {
        ActorPhysics* first = mAxisList.at(i-1);
        ActorPhysics* second = mAxisList.at(i);
        if (collides(first->box, second->box)) {
            mEventManager->queueEvent(new ActorCollidesEventData( first->actorId,
                                                                    second->actorId,
                                                                    first->lastMovement + second->lastMovement));
        }
    }
}

static bool compareXAxis(const ActorPhysics* first, const ActorPhysics* second) {
    return (first->box.min.x < second->box.min.x);
}


void PhysicsSystem::initAxisList(std::list<Actor*> actors) {
    for (auto it = actors.begin(); it != actors.end(); ++it) {
        Actor* actor = (*it);
        if (actor->hasComponent("BidimensionalComponent")
            && actor->hasComponent("BoundingSquareComponent")) {
            ActorPhysics* actorPhysics = createActorPhysics(actor);
            mAxisList.push_back(actorPhysics);
        }
    }

    std::sort(mAxisList.begin(), mAxisList.end(), compareYAxis);
}

ActorPhysics* PhysicsSystem::createActorPhysics(Actor* actor) {
    BoundingSquareComponent* squareComponent = reinterpret_cast<BoundingSquareComponent*>
                                            (actor->getComponent("BoundingSquareComponent"));

    BidimensionalComponent* positionComponent = reinterpret_cast<BidimensionalComponent*>
                (actor->getComponent("BidimensionalComponent"));
    AABB box = AABB();
    box.min = positionComponent->getPos();
    box.max = box.min + squareComponent->getDimensions();
    ActorPhysics *phys = new ActorPhysics();
    phys->box = box;
    phys->actorId = actor->getId();
    phys->lastMovement = Vector2D();
    return phys;
}

void PhysicsSystem::init(Scene* scene) {
    initAxisList(scene->getActors());
    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                &PhysicsSystem::updatePosition),
                                "MoveActorEventDataType");
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

void PhysicsSystem::updatePosition(IEventData* pEventData) {
    MoveActorEventData* moveEvent = reinterpret_cast<MoveActorEventData*>(pEventData);
    // Should look for the actor inside the mAxisList and update it.
    ActorPhysics* physics = findActor(moveEvent->getActorId());
    Vector2D lastMovement = moveEvent->getDelta();
    physics->lastMovement = lastMovement;
    physics->box += lastMovement;
}
