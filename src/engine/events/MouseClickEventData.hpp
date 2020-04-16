#pragma once
#include <vector>
#include <string>
#include "BaseEventData.hpp"
#include "../Vector2d.hpp"

class MouseClickEventData : public BaseEventData {
 private:
    int mMouseButton;
 public:
    // 0: Left Click
    // 1: Right Click
    // 2: Middle Click
    MouseClickEventData(int mouseButton) {
        mMouseButton = mouseButton;
    }

    int getMouseButton() {
        return mMouseButton;
    }

    std::string getEventType(void) const {
        return "MouseClickEventDataType";
    }
};
