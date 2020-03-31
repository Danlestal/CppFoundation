#include "InvaderBehaviourComponent.hpp"
#include "../../events/OrderActorToMoveEventData.hpp"

InvaderBehaviourComponent::InvaderBehaviourComponent(long actorId, EventManager* evtManager) {
    mEventManager = evtManager;
    mSpeedVector = Vector2D(5, 0);
    mActorId = actorId;
}

void InvaderBehaviourComponent::update(Vector2D position) {
    if ((position.x > 400) || (position.x < 0)) {
        mSpeedVector *= (-1);
        mEventManager->triggerEvent(
            new OrderActorToMoveEventData(
                mActorId,
                mSpeedVector + Vector2D(0, 5)));
    }

    mEventManager->queueEvent(new OrderActorToMoveEventData(mActorId, mSpeedVector));
}
