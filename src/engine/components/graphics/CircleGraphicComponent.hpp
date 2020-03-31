#pragma once
#include "GraphicComponent.hpp"
class CircleGraphicComponent : public GraphicComponent {
 public:
    CircleGraphicComponent();
    void draw(Vector2D position);
};
