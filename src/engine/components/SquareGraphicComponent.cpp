#include "SquareGraphicComponent.hpp"

void SquareGraphicComponent::draw(Vector2D pos) {
    DrawRectangle(pos.x, pos.y, mHeight, mWidth, RED);
}
