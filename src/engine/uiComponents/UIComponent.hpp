#pragma once
#include <string>
#include "../Vector2d.hpp"

class UIComponent {
 public:
    virtual void draw(Vector2D offsetVector) = 0;
    virtual ~UIComponent() {}
};
