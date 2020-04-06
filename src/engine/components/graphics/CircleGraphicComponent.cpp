#include "CircleGraphicComponent.hpp"

CircleGraphicComponent::CircleGraphicComponent(): GraphicComponent() {}

void CircleGraphicComponent::draw(Vector2D position) {
    DrawCircle(position.x, position.y, 10, BLACK);
}
