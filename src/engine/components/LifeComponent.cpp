#include "LifeComponent.hpp"


LifeComponent::LifeComponent(long actorId, int initialLife, EventManager* eventManager) {
    mLife = initialLife;
    mActorId = actorId;
    mEventManager = eventManager;
    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                            &LifeComponent::collisionDetected),
                                            "ActorCollidesEventDataType");
}


LifeComponent::~LifeComponent(void) {
    mEventManager->removeListener(fastdelegate::MakeDelegate(this,
                                                &LifeComponent::collisionDetected),
                                                "ActorCollidesEventDataType");
}

int LifeComponent::reduceLife(int lifeDecrement) {
    mLife -= lifeDecrement;
    if (mLife <= 0) {
        mEventManager->queueEvent(new DestroyActorEventData(mActorId));
    }
    return mLife;
}

int LifeComponent::getLife() {
    return mLife;
}

void LifeComponent::collisionDetected(IEventData* event) {
    ActorCollidesEventData* collisionEvent = reinterpret_cast<ActorCollidesEventData*>(event);
    if ((collisionEvent->getActorId() == mActorId) || (collisionEvent->getCollidesWithId() == mActorId)) {
        if (!collisionEvent->boundaryCollision()) {
            reduceLife(1);
        }
    }
}

std::string LifeComponent::getType() {
    return "LifeComponent";
}
