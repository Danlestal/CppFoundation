#pragma once
#include <string>
#include <map>
#include "raylib.h"


class XenonTextureMap {
 public:
  enum XenonSprite {
        SPACESHIP,
        SPACESHIP_LEFT,
        SPACESHIP_EXTREME_LEFT,
        SPACESHIP_RIGHT,
        SPACESHIP_EXTREME_RIGHT
      };

 private:
    Texture2D mTexture;
    std::map<XenonSprite, Rectangle> mTextureMap;

 public:
     XenonTextureMap();
     explicit XenonTextureMap(Texture2D texture);
     Rectangle getRectangle(int index);
     Texture2D getTexture();
};
