#pragma once
#include <string>
#include "raylib.h"

class TextureMap {
 private:
    Texture2D mTexture;

 public:
     explicit TextureMap(Texture2D texture);
     Rectangle getRectangle(std::string pos);
     Texture2D getTexture();
};
