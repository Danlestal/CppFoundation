#pragma once
#include <vector>
#include <string>
#include "BaseEventData.hpp"
#include "../Vector2d.hpp"

class TickEventData : public BaseEventData {
 public:
    TickEventData() {}

    std::string getEventType(void) const {
        return "TickEventDataType";
    }
};
