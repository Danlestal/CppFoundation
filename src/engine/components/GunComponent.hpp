#pragma once
#include <string>
#include "Component.hpp"
#include "../Vector2d.hpp"
#include "../events/IEventData.hpp"
#include "../events/UpdateActorPositionEventData.hpp"

class GunComponent : public Component {
 private:
    Vector2D mPosition;
 public:
    explicit GunComponent(Vector2D initialPosition);
    std::string getType();
    void updatePosition(IEventData* pEventData);
    void receiveShotOrder(IEventData* pEventData);
};
