#pragma once
#include <vector>
#include <string>
#include "BaseEventData.hpp"

class MoveActorEventData : public BaseEventData {
 private:
    int mIncrementX;
    int mIncrementY;
    long mActorId;
 public:
    explicit MoveActorEventData(long actorId, int incrementX, int incrementY) {
        mIncrementX = incrementX;
        mIncrementY = incrementY;
        mActorId = actorId;
    }

    int getIncrementX() {
        return mIncrementX;
    }

    int getIncrementY() {
        return mIncrementY;
    }

    std::string getEventType(void) const {
        return "MoveActorEventDataType";
    }
};
