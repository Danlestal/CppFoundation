#pragma once
#include <string>
#include "../Vector2d.hpp"
#include "BaseEventData.hpp"

class ActorCollidesEventData : public BaseEventData {
 private:
    long mActorId;
    long mCollidesWithId;
    Vector2D mCollisionVector;
    bool mBoundaryCollision;

 public:
    explicit ActorCollidesEventData( long actorId,
                            long collidesWithId,
                            Vector2D collisionVector,
                            bool boundaryCollision) {
        mActorId = actorId;
        mCollidesWithId = collidesWithId;
        mCollisionVector = collisionVector;
        mBoundaryCollision = boundaryCollision;
    }

    long getActorId() {
        return mActorId;
    }

    long getCollidesWithId() {
        return mCollidesWithId;
    }

    bool boundaryCollision(){
        return mBoundaryCollision;
    }

    Vector2D getCollisionVector() {
        return mCollisionVector;
    }

    std::string getEventType(void) const {
        return "ActorCollidesEventDataType";
    }
};
