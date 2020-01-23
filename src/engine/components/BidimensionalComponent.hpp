#pragma once
#include <string>
#include "Component.hpp"
#include "../events/MoveActorEventData.hpp"
#include "../events/EventManager.hpp"
#include "../Vector2d.hpp"

class BidimensionalComponent : public Component {
 private:
    Vector2D mPosition;
    long mActorId;

 public:
    BidimensionalComponent(long actorId, Vector2D position) {
        mPosition = position;
        mActorId = actorId;
    }

    void updatePosition(IEventData* pEventData) {
        MoveActorEventData* moveEvent = reinterpret_cast<MoveActorEventData*>(pEventData);
        if (moveEvent->getActorId() == mActorId) {
            mPosition += moveEvent->getDelta();
        }
    }


    Vector2D getPos() {
        return mPosition;
    }

    void setPos(Vector2D position) {
        mPosition = position;
    }

    std::string getType() {
        return "BidimensionalComponent";
    }
};
