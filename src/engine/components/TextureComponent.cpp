#include "TextureComponent.hpp"

TextureComponent::TextureComponent(int height, int width, XenonTextureMap textureMap): GraphicComponent() {
    mHeight = height;
    mWidth = width;
    mTextureMap = textureMap;
}

void TextureComponent::draw(Vector2D pos) {
    DrawTextureRec(mTextureMap.getTexture(),
                    mTextureMap.getRectangle(0),
                    {pos.x, pos.y},
                    WHITE);
}
