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
   XenonTextureMap() {
      mTexture = {};
      mTextureMap = {};
   }

   explicit XenonTextureMap(Texture2D texture) {
      mTexture = texture;
      mTextureMap = {
         {SPACESHIP, { 66.0f, 99.0f, 32.0f, 28.0f }},
         {SPACESHIP_LEFT, { 33.0f, 99.0f, 32.0f, 28.0f }},
         {SPACESHIP_EXTREME_LEFT, { 0.0f, 99.0f, 32.0f, 28.0f }},
         {SPACESHIP_RIGHT, { 99.0f, 99.0f, 32.0f, 28.0f }},
         {SPACESHIP_EXTREME_RIGHT, { 132.0f, 99.0f, 32.0f, 28.0f }}
      };
   }

   Rectangle getRectangle(int index) {
      return mTextureMap[(XenonSprite)index];
   }
};
