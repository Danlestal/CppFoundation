#pragma once
#include <string>
#include "../Vector2d.hpp"
#include "BaseEventData.hpp"

class ActorCollidesEventData : public BaseEventData {
 private:
    long mActorId;
    long mCollidesWithId;

 public:
    ActorCollidesEventData( long actorId,
                            long collidesWithId) {
        mActorId = actorId;
        mCollidesWithId = collidesWithId;
    }

    long getActorId() {
        return mActorId;
    }

    long getCollidesWithId() {
        return mCollidesWithId;
    }

    std::string getEventType(void) const {
        return "ActorCollidesEventData";
    }
};
