#include "VerticalCameraComponent.hpp"


VerticalCameraComponent::VerticalCameraComponent(long actorId, EventManager* evtManager) {
    mActorId = actorId;
    mEventManager = evtManager;
    mSpeedVector = Vector2D(0, -0.25);
}

VerticalCameraComponent::~VerticalCameraComponent(void) {}

void VerticalCameraComponent::update(Vector2D currentPosition ) {
    mEventManager->queueEvent(new OrderActorToMoveEventData(mActorId, mSpeedVector));
}

