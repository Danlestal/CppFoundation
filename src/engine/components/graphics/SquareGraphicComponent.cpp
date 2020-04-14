#include "SquareGraphicComponent.hpp"

SquareGraphicComponent::SquareGraphicComponent(int height, int width): GraphicComponent() {
        mHeight = height;
        mWidth = width;
        mOffset = Vector2D();
        mColor = RED;
}

SquareGraphicComponent::SquareGraphicComponent(int height,
                                                int width,
                                                Vector2D offset,
                                                Color color): GraphicComponent() {
        mHeight = height;
        mWidth = width;
        mOffset = offset;
        mColor = color;
}

void SquareGraphicComponent::draw(Vector2D pos) {
    DrawRectangle(pos.x + mOffset.x,
                    pos.y + mOffset.y,
                    mHeight,
                    mWidth,
                    mColor);
}
