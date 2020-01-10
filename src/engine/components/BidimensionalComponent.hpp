#pragma once
#include <string>
#include "Component.hpp"
#include "../events/MovePlayerEventData.hpp"
#include "../events/EventManager.hpp"

class BidimensionalComponent : public Component {
 private:
    int mPosX;
    int mPosY;

 public:
    BidimensionalComponent(int spawnX, int spawnY) {
        mPosX = spawnX;
        mPosY = spawnY;
    }


    void updatePosition(IEventData* pEventData) {
        TraceLog(LOG_INFO, "Updating position");
        MovePlayerEventData* moveEvent = reinterpret_cast<MovePlayerEventData*>(pEventData);
        mPosX += moveEvent->getIncrementX();
        mPosY += moveEvent->getIncrementY();
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
