#pragma once
#include "GraphicComponent.hpp"
class CircleGraphicComponent : public GraphicComponent {
 public:
    explicit CircleGraphicComponent(EventManager* eventManager): GraphicComponent(eventManager) {}
    void draw();
};
