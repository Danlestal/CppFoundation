#pragma once
#include <string>
#include "Component.hpp"

class BidimensionalComponent : public Component {
 private:
    int mPosX;
    int mPosY;

 public:
    BidimensionalComponent(int spawnX, int spawnY) {
        mPosX = spawnX;
        mPosY = spawnY;
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
