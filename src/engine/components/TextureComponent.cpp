#include "TextureComponent.hpp"

TextureComponent::TextureComponent(int height, int width, Texture2D texture): GraphicComponent() {
    mHeight = height;
    mWidth = width;
    mTexture = texture;
}

void TextureComponent::draw(Vector2D pos) {
    DrawTexture(mTexture, pos.x, pos.y, WHITE);
}
