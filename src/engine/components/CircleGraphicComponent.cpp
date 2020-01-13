#include "CircleGraphicComponent.hpp"

void CircleGraphicComponent::draw(Vector2D position) {
    DrawCircle(position.x, position.y, 30, BLACK);
}
