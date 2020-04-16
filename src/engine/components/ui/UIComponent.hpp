#pragma once
#include <string>
#include "../../Vector2d.hpp"
#include "../Component.hpp"

class UIComponent : public Component {
 public:
    virtual void draw(Vector2D) = 0;
    const std::string TYPE = "UIComponent";
    std::string getType() { return TYPE; }
};
