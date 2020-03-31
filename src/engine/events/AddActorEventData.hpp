#pragma once
#include <string>
#include "BaseEventData.hpp"

class AddActorEventData : public BaseEventData {
 private:
    long mActorId;

 public:
    explicit AddActorEventData(long actorId) {
        mActorId = actorId;
    }

    long getActorId() {
        return mActorId;
    }

    std::string getEventType(void) const {
        return "AddActorEventDataType";
    }
};
