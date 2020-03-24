#include "TextureComponent.hpp"

TextureComponent::TextureComponent(int height, int width, Texture2D texture): GraphicComponent() {
    mHeight = height;
    mWidth = width;
    mTexture = texture;
    mCurrentFrame = { 66.0f, 99.0f, 32.0f, 28.0f };
}

void TextureComponent::draw(Vector2D pos) {
    DrawTextureRec(mTexture, mCurrentFrame, {pos.x, pos.y}, WHITE);
}
