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
    MoveActorEventData(long actorId, int incrementX, int incrementY) {
        mIncrementX = incrementX;
        mIncrementY = incrementY;
        mActorId = actorId;
    }

    long getActorId() {
        return mActorId;
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
