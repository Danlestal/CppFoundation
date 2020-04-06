#include "InvaderBehaviourComponent.hpp"


InvaderBehaviourComponent::InvaderBehaviourComponent(long actorId, EventManager* evtManager) {
    mEventManager = evtManager;
    mSpeedVector = Vector2D(2, 0);
    mActorId = actorId;
    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                &InvaderBehaviourComponent::receiveCollision),
                                                "ActorCollidesEventDataType");
}


InvaderBehaviourComponent::~InvaderBehaviourComponent(void) {
    mEventManager->removeListener(fastdelegate::MakeDelegate(this,
                                                &InvaderBehaviourComponent::receiveCollision),
                                                "ActorCollidesEventDataType");
}

void InvaderBehaviourComponent::update(Vector2D position) {
    mEventManager->queueEvent(new OrderActorToMoveEventData(mActorId, mSpeedVector));
}

void InvaderBehaviourComponent::receiveCollision(IEventData* pEventData) {
    ActorCollidesEventData* collisionEvent = reinterpret_cast<ActorCollidesEventData*>(pEventData);
    if (collisionEvent->getActorId() == mActorId) {
        if (collisionEvent->boundaryCollision()) {
            // make invader bounce for the lulz
            mSpeedVector = mSpeedVector - collisionEvent->getCollisionVector();
        } else {
            mEventManager->queueEvent(new DestroyActorEventData(mActorId));
            mEventManager->queueEvent(new InvaderKilledEventData());
        }
    }
}
