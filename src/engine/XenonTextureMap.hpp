#pragma once
#include <string>
#include <map>
#include "raylib.h"

#include "TextureMap.hpp"


class XenonTextureMap : public TextureMap {
 public:
  enum XenonSprite {
        SPACESHIP,
        SPACESHIP_LEFT,
        SPACESHIP_EXTREME_LEFT,
        SPACESHIP_RIGHT,
        SPACESHIP_EXTREME_RIGHT
      };

 private:
    std::map<XenonSprite, Rectangle> mTextureMap;

 public:
     XenonTextureMap();
     explicit XenonTextureMap(Texture2D texture);
     Rectangle getRectangle(int index);
};
