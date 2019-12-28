#include "GraphicComponent.hpp"

void GraphicComponent::draw(int posX, int posY) {
        DrawRectangle(posX, posY, 30, 30, BLACK);
}

std::string GraphicComponent::getType() {
    return "LifeComponent";
}
