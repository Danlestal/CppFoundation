#pragma once
#include <string>
#include "raylib.h"
#include "Component.hpp"
#include "../events/OrderActorToMoveEventData.hpp"
#include "../events/UpdateActorPositionEventData.hpp"
#include "../events/ActorCollidesEventData.hpp"
#include "../events/EventManager.hpp"
#include "../Vector2d.hpp"

class BidimensionalComponent : public Component {
 private:
    EventManager* mEvtManager;
    Vector2D mPosition;
    Vector2D mForbiddenDirection;

 public:
    BidimensionalComponent(long actorId, Vector2D position, EventManager* evtManager);

    void updatePosition(IEventData* pEventData);

    void receiveCollision(IEventData* pEventData);

    Vector2D getPos();

    void setPos(Vector2D position);

    std::string getType();
};
