#pragma once
#include <string>
#include "../Vector2d.hpp"
#include "BaseEventData.hpp"

class ActorCollidesEventData : public BaseEventData {
 private:
    long mActorId;
    long mCollidesWithId;
    Vector2D mCollisionVector;

 public:
    explicit ActorCollidesEventData( long actorId,
                            long collidesWithId,
                            Vector2D collisionVector) {
        mActorId = actorId;
        mCollidesWithId = collidesWithId;
        mCollisionVector = collisionVector;
    }

    long getActorId() {
        return mActorId;
    }

    long getCollidesWithId() {
        return mCollidesWithId;
    }

    Vector2D getCollisionVector() {
        return mCollisionVector;
    }

    std::string getEventType(void) const {
        return "ActorCollidesEventDataType";
    }
};
