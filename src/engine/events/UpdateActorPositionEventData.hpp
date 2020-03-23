#pragma once
#include <vector>
#include <string>
#include "BaseEventData.hpp"
#include "../Vector2d.hpp"

class UpdateActorPositionEventData : public BaseEventData {
 private:
    Vector2D mDelta;
    long mActorId;
 public:
    UpdateActorPositionEventData(long actorId, Vector2D delta) {
        mDelta = delta;
        mActorId = actorId;
    }

    long getActorId() {
        return mActorId;
    }

    Vector2D getDelta() {
        return mDelta;
    }

    std::string getEventType(void) const {
        return "UpdateActorPositionEventDataType";
    }
};
