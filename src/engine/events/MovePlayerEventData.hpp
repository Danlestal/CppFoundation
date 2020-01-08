#pragma once
#include <vector>
#include <string>
#include "BaseEventData.hpp"

class MovePlayerEventData : public BaseEventData {
 private:
    int mIncrementX;
    int mIncrementY;
 public:
    explicit MovePlayerEventData(int incrementX, int incrementY) {
        mIncrementX = incrementX;
        mIncrementY = incrementY;
    }

    int getIncrementX() {
        return mIncrementX;
    }

    int getIncrementY() {
        return mIncrementY;
    }

    std::string getEventType(void) const {
        return "MovePlayerEventDataType";
    }
};
