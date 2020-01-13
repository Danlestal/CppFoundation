#include "SquareGraphicComponent.hpp"

void SquareGraphicComponent::draw(int posX, int posY) {
    DrawRectangle(posX, posY, mHeight, mWidth, RED);
}
