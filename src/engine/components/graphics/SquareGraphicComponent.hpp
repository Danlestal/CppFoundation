#pragma once
#include "GraphicComponent.hpp"
#include "../../Vector2d.hpp"

class SquareGraphicComponent : public GraphicComponent {
 private:
    int mHeight;
    int mWidth;
    Vector2D mOffset;
    Color mColor;
 public:
    SquareGraphicComponent(int height, int width);
    SquareGraphicComponent(int height, int width, Vector2D offset, Color color);
    void draw(Vector2D pos);
};
