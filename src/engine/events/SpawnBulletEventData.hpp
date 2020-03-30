#pragma once
#include <string>
#include "../Vector2d.hpp"
#include "BaseEventData.hpp"

class SpawnBulletEventData : public BaseEventData {
 private:
    Vector2D mInitialPosition;

 public:
    explicit SpawnBulletEventData(Vector2D initialPosition) {
        mInitialPosition = initialPosition;
    }

    Vector2D getInitialPosition() {
        return mInitialPosition;
    }

    std::string getEventType(void) const {
        return "SpawnBulletEventDataType";
    }
};
