#pragma once
#include "GraphicComponent.hpp"
class SquareGraphicComponent : public GraphicComponent {
 public:
    explicit SquareGraphicComponent(EventManager* eventManager): GraphicComponent(eventManager) {}
    void draw(int posX, int posY);
};
