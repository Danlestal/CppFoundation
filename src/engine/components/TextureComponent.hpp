#pragma once
#include "GraphicComponent.hpp"
#include "../XenonTextureMap.hpp"
#include "../Vector2d.hpp"
class TextureComponent : public GraphicComponent {
 private:
    int mHeight;
    int mWidth;
    XenonTextureMap mTextureMap;
 public:
     TextureComponent(int height, int width, XenonTextureMap textureMap);
     void draw(Vector2D pos);
};
