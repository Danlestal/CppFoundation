#include "TextureComponent.hpp"

TextureComponent::TextureComponent(int height, int width): GraphicComponent() {
    mHeight = height;
    mWidth = width;
}

void TextureComponent::draw(Vector2D pos) {
    DrawRectangle(pos.x, pos.y, mHeight, mWidth, RED);
}