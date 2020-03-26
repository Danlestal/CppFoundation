#include "XenonTextureMap.hpp"

XenonTextureMap::XenonTextureMap(){
    mTexture = {};
    mTextureMap = {};
}

XenonTextureMap::XenonTextureMap(Texture2D texture) {
    mTexture = texture;
    mTextureMap = {
        {SPACESHIP, { 66.0f, 99.0f, 32.0f, 28.0f }},
        {SPACESHIP_LEFT, { 33.0f, 99.0f, 32.0f, 28.0f }},
        {SPACESHIP_EXTREME_LEFT, { 0.0f, 99.0f, 32.0f, 28.0f }},
        {SPACESHIP_RIGHT, { 99.0f, 99.0f, 32.0f, 28.0f }},
        {SPACESHIP_EXTREME_RIGHT, { 132.0f, 99.0f, 32.0f, 28.0f }},
    };
}


Rectangle XenonTextureMap::getRectangle(int index) {
    return mTextureMap[(XenonSprite)index];
}
