#pragma once
#include "GraphicComponent.hpp"
#include "../Vector2d.hpp"
class TextureComponent : public GraphicComponent {
 private:
    int mHeight;
    int mWidth;
    Texture2D mTexture;
    Rectangle mCurrentFrame;
 public:
     TextureComponent(int height, int width, Texture2D texture);
     void draw(Vector2D pos);
};
