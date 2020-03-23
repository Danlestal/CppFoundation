#pragma once
#include "GraphicComponent.hpp"
class CircleGraphicComponent : public GraphicComponent {
 public:
    explicit CircleGraphicComponent(): GraphicComponent() {}
    void draw(Vector2D position);
};
