#include "GunComponent.hpp"

GunComponent::GunComponent(long actorId, Vector2D initialPosition, EventManager* evtManager) {
    mPosition = initialPosition;
    mEventManager = evtManager;
    mActorId = actorId;
    mTickCounter = 0;
}

void GunComponent::updatePosition(IEventData* pEventData) {
    UpdateActorPositionEventData* moveEvent = reinterpret_cast<UpdateActorPositionEventData*>(pEventData);
    Vector2D lastMovement = moveEvent->getDelta();
    mPosition += lastMovement;
}

void GunComponent::receiveShotOrder(IEventData* event) {
    OrderActorToShotEventData* orderEvent = reinterpret_cast<OrderActorToShotEventData*>(event);
    if (mActorId == orderEvent->getActorId()) {
        if (mTickCounter == GUN_FREQUENCY) {
            mTickCounter = 0;
            mEventManager->queueEvent(new SpawnBulletEventData(mPosition));
        }
    }
}

std::string GunComponent::getType() {
    return "GunComponent";
}
