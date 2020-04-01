#include "GunComponent.hpp"

GunComponent::GunComponent(long actorId, Vector2D initialPosition, EventManager* evtManager) {
    mPosition = initialPosition;
    mEventManager = evtManager;
    mActorId = actorId;
    mTicksSinceLastShot = 0;
    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                            &GunComponent::updatePosition),
                                                            "UpdateActorPositionEventDataType");
    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                        &GunComponent::receiveShotOrder),
                                                        "OrderActorToShotEventDataType");
    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                            &GunComponent::receiveTick),
                                                            "TickEventDataType");
}

GunComponent::~GunComponent() {
    mEventManager->removeListener(fastdelegate::MakeDelegate(this,
                                                            &GunComponent::updatePosition),
                                                            "UpdateActorPositionEventDataType");
    mEventManager->removeListener(fastdelegate::MakeDelegate(this,
                                                        &GunComponent::receiveShotOrder),
                                                        "OrderActorToShotEventDataType");
    mEventManager->removeListener(fastdelegate::MakeDelegate(this,
                                                            &GunComponent::receiveTick),
                                                            "TickEventDataType");
}

void GunComponent::updatePosition(IEventData* pEventData) {
    UpdateActorPositionEventData* moveEvent = reinterpret_cast<UpdateActorPositionEventData*>(pEventData);
    if (moveEvent->getActorId() == mActorId) {
        UpdateActorPositionEventData* moveEvent = reinterpret_cast<UpdateActorPositionEventData*>(pEventData);
        Vector2D lastMovement = moveEvent->getDelta();
        mPosition += lastMovement;
    }
}

void GunComponent::receiveShotOrder(IEventData* event) {
    OrderActorToShotEventData* orderEvent = reinterpret_cast<OrderActorToShotEventData*>(event);
    if (mActorId == orderEvent->getActorId()) {
        if (mTicksSinceLastShot >= GUN_FREQUENCY) {
            mTicksSinceLastShot = 0;
            Vector2D spawnPosition = mPosition + Vector2D(8, -18);
            mEventManager->queueEvent(new SpawnBulletEventData(spawnPosition));
        }
    }
}

void GunComponent::receiveTick(IEventData* event) {
    if (mTicksSinceLastShot < GUN_FREQUENCY + 10) {
        mTicksSinceLastShot++;
    }
}

std::string GunComponent::getType() {
    return "GunComponent";
}
