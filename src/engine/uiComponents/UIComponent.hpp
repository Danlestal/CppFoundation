#pragma once
#include <string>
#include "../../Vector2d.hpp"
#include "../Component.hpp"

class UIComponent {
 public:
    virtual void draw(Vector2D) = 0;
};
