#pragma once
#include <vector>
#include <string>
#include "BaseEventData.hpp"
#include "../Vector2d.hpp"

class ActorQueryEventData : public BaseEventData {
 private:
  Vector2D mPositionToQuery;

 public:
    explicit ActorQueryEventData(Vector2D positionToQuery) {
        mPositionToQuery = positionToQuery;
    }

    Vector2D getPositionToQuery() {
        return mPositionToQuery;
    }

    std::string getEventType(void) const {
        return "ActorQueryEventDataType";
    }
};
