#pragma once
#include <vector>
#include <string>
#include "BaseEventData.hpp"
#include "../Vector2d.hpp"

class OrderActorToShotEventData : public BaseEventData {
 private:
    long mActorId;
 public:
    explicit OrderActorToShotEventData(long actorId) {
        mActorId = actorId;
    }

    long getActorId() {
        return mActorId;
    }

    std::string getEventType(void) const {
        return "OrderActorToShotEventDataType";
    }
};