#include "XenonTextureMap.hpp"

XenonTextureMap::XenonTextureMap(){
    mTexture = {};
    mTextureMap = {};
}

XenonTextureMap::XenonTextureMap(Texture2D texture) {
    mTexture = texture;
    mTextureMap = {
        {SPACESHIP, { 66.0f, 99.0f, 32.0f, 28.0f }},
    };
}

Texture2D XenonTextureMap::getTexture() {
    return mTexture;
}

Rectangle XenonTextureMap::getRectangle(int index) {
    return mTextureMap[(XenonSprite)index];
}
