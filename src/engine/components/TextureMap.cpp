#include "TextureMap.hpp"

TextureMap::TextureMap(Texture2D texture) {
    mTexture = texture;
}

Texture2D TextureMap::getTexture() {
    return mTexture;
}
