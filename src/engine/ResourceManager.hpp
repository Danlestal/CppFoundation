#pragma once
#include <string>
#include <map>
#include "raylib.h"

class ResourceManager {
 private:
      std::map<std::string, Texture2D> mTextureStorage;
 public:
      void loadTexture(std::string textureName, std::string texturePath);
      Texture2D getTexture(std::string texturePath);
};
