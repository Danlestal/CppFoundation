#include "BehaviourComponent.hpp"
#include "../events/MoveActorEventData.hpp"

BehaviourComponent::BehaviourComponent(long actorId, EventManager* evtManager) {
    mEventManager = evtManager;
    mHorizontalDirection = 1;
    mActorId = actorId;
    mSpeed = 5;
}

void BehaviourComponent::update(int posX, int posY) {
    if ((posX > 400) || (posX< 0)) {
        mHorizontalDirection *= (-1);
        mEventManager->triggerEvent(new MoveActorEventData(mActorId, mHorizontalDirection * mSpeed, mSpeed));
    }

    mEventManager->triggerEvent(new MoveActorEventData(mActorId, mHorizontalDirection * mSpeed, 0));
}
