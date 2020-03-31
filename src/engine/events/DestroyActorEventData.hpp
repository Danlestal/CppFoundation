#pragma once
#include <string>
#include "BaseEventData.hpp"

class DestroyActorEventData : public BaseEventData {
 private:
    long mActorId;

 public:
    explicit DestroyActorEventData( long actorId) {
        mActorId = actorId;
    }

    long getActorId() {
        return mActorId;
    }

    std::string getEventType(void) const {
        return "DestroyActorEventDataType";
    }
};