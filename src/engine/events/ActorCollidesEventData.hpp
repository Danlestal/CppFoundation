#pragma once
#include <vector>
#include <string>
#include "BaseEventData.hpp"

class ActorCollidesEventData : public BaseEventData {
 private:
    long mActorId;
 public:
    ActorCollidesEventData(long actorId) {
        mActorId = actorId;
    }

    long getActorId() {
        return mActorId;
    }

    std::string getEventType(void) const {
        return "ActorCollidesEventData";
    }
};
