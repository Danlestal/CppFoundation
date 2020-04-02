#include "ResourceManager.hpp"

void ResourceManager::loadTexture(std::string textureName, std::string texturePath) {
    mTextureStorage[textureName] = LoadTexture(texturePath.c_str());
}

Texture2D ResourceManager::getTexture(std::string textureName) {
    return mTextureStorage[textureName];
}