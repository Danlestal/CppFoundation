#include "GunComponent.hpp"

GunComponent::GunComponent(Vector2D initialPosition) {
    mPosition = initialPosition;
}

void GunComponent::updatePosition(IEventData* pEventData) {
    UpdateActorPositionEventData* moveEvent = reinterpret_cast<UpdateActorPositionEventData*>(pEventData);
    Vector2D lastMovement = moveEvent->getDelta();
    mPosition += lastMovement;
}

void GunComponent::receiveShotOrder(IEventData* pEventData) {

}

std::string GunComponent::getType() {
    return "GunComponent";
}
