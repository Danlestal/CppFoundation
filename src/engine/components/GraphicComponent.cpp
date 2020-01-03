#include "GraphicComponent.hpp"

void GraphicComponent::draw() {
        DrawRectangle(mPosX, mPosY, 30, 30, BLACK);
}

std::string GraphicComponent::getType() {
    return "GraphicComponent";
}
