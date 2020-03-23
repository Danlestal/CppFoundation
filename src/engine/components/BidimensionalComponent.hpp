#pragma once
#include <string>
#include "raylib.h"
#include "Component.hpp"
#include "../events/MoveActorEventData.hpp"
#include "../events/UpdateActorPositionEventData.hpp"
#include "../events/ActorCollidesEventData.hpp"
#include "../events/EventManager.hpp"
#include "../Vector2d.hpp"

class BidimensionalComponent : public Component {
 private:
    EventManager* mEvtManager;
    Vector2D mPosition;
    Vector2D mForbiddenDirection;
    long mActorId;

 public:
    BidimensionalComponent(long actorId, Vector2D position, EventManager* evtManager) {
        mPosition = position;
        mActorId = actorId;
        mForbiddenDirection = Vector2D();
        mEvtManager = evtManager;
    }

    void updatePosition(IEventData* pEventData) {
        MoveActorEventData* moveEvent = reinterpret_cast<MoveActorEventData*>(pEventData);
        if (moveEvent->getActorId() == mActorId) {
            Vector2D realDelta = moveEvent->getDelta() - mForbiddenDirection;
            if (realDelta.x != 0 || realDelta.y != 0) {
                mPosition += realDelta;
                mForbiddenDirection = Vector2D();
                mEvtManager->queueEvent(new UpdateActorPositionEventData(mActorId, realDelta));
            }
        }
    }

    void receiveCollision(IEventData* pEventData) {
        ActorCollidesEventData* collisionEvent = reinterpret_cast<ActorCollidesEventData*>(pEventData);
        if ((collisionEvent->getActorId() == mActorId) || (collisionEvent->getCollidesWithId() == mActorId)) {
            mForbiddenDirection = collisionEvent->getCollisionVector();
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
