#pragma once
#include <string>
#include <map>
#include "raylib.h"

class TextureMap {
 protected:
    Texture2D mTexture;
 public:
     virtual Rectangle getRectangle(int index) = 0;
     Texture2D getTexture() {
        return mTexture;
     }
};
