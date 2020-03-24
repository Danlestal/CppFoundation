#include "SquareGraphicComponent.hpp"

SquareGraphicComponent::SquareGraphicComponent(int height, int width): GraphicComponent() {
        mHeight = height;
        mWidth = width;
}

void SquareGraphicComponent::draw(Vector2D pos) {
    DrawRectangle(pos.x, pos.y, mHeight, mWidth, RED);
}
