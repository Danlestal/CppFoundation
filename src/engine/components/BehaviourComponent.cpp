#include "BehaviourComponent.hpp"
#include "../events/MoveActorEventData.hpp"

BehaviourComponent::BehaviourComponent(long actorId, EventManager* evtManager) {
    mEventManager = evtManager;
    mSpeedVector = Vector2D(5, 0);
    mActorId = actorId;
}

void BehaviourComponent::update(Vector2D position) {
    if ((position.x > 400) || (position.x < 0)) {
        mSpeedVector *= (-1);
        mEventManager->triggerEvent(
            new MoveActorEventData(
                mActorId,
                mSpeedVector + Vector2D(0, 5)));
    }

    mEventManager->triggerEvent(new MoveActorEventData(mActorId, mSpeedVector));
}
