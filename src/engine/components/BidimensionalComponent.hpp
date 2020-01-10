#pragma once
#include <string>
#include "Component.hpp"
#include "../events/MoveActorEventData.hpp"
#include "../events/EventManager.hpp"

class BidimensionalComponent : public Component {
 private:
    int mPosX;
    int mPosY;
    long mActorId;

 public:
    BidimensionalComponent(long actorId, int spawnX, int spawnY) {
        mPosX = spawnX;
        mPosY = spawnY;
        mActorId = actorId;
    }

    void updatePosition(IEventData* pEventData) {
        MoveActorEventData* moveEvent = reinterpret_cast<MoveActorEventData*>(pEventData);
        if (moveEvent->getActorId() == mActorId) {
            mPosX += moveEvent->getIncrementX();
            mPosY += moveEvent->getIncrementY();
        }
    }


    int getPosx() {
        return mPosX;
    }

    int setPosx(int posX) {
        mPosX = posX;
    }

    int getPosY() {
        return mPosY;
    }

    void setPosY(int posY) {
        mPosY = posY;
    }

    std::string getType() {
        return "BidimensionalComponent";
    }
};
