#pragma once
#include "GraphicComponent.hpp"
class GraphicComponentWithTexture : public GraphicComponent {
 public:
    explicit GraphicComponentWithTexture(EventManager* eventManager): GraphicComponent(eventManager) {}
    void draw();
};
