#pragma once
#include <vector>
#include <string>
#include "BaseEventData.hpp"
#include "../Vector2d.hpp"

class InvaderKilledEventData : public BaseEventData {
 public:
    InvaderKilledEventData() {}

    std::string getEventType(void) const {
        return "InvaderKilledEventDataType";
    }
};
