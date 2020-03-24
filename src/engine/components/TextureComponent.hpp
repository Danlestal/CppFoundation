#pragma once
#include "GraphicComponent.hpp"
#include "../Vector2d.hpp"
class TextureComponent : public GraphicComponent {
 private:
    int mHeight;
    int mWidth;
 public:
    explicit TextureComponent(int height, int width);
    void draw(Vector2D pos);
};
