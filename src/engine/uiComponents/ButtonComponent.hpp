#pragma once
#include <string>
#include "raygui.h"
#include "UIComponent.hpp"
#include "../../Vector2d.hpp"

class ButtonComponent : public UIComponent {
 private:
    Vector2D mDimensions;
    std::string mName;
    std::string mText;
 public:
    ButtonComponent(Vector2D dimensions, std::string name, std::string text);
    void draw(Vector2D pos);
};
