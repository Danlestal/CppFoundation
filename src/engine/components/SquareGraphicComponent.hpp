#pragma once
#include "GraphicComponent.hpp"
class SquareGraphicComponent : public GraphicComponent {
 private:
    int mHeight;
    int mWidth;
 public:
    explicit SquareGraphicComponent(int height, int width, EventManager* eventManager): GraphicComponent(eventManager) {
        mHeight = height;
        mWidth = width;
    }
    void draw(int posX, int posY);
};
