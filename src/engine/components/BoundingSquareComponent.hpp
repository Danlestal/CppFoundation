#pragma once
#include <string>
#include "Component.hpp"
#include "../Vector2d.hpp"

class BoundingSquareComponent : public Component {
 private:
  Vector2D mDimensions;
  bool mBoundary;

 public:
    explicit BoundingSquareComponent(Vector2D dimensions);
    BoundingSquareComponent(Vector2D dimensions, bool boundary);
    ~BoundingSquareComponent();

    Vector2D getDimensions();

    std::string getType();
    bool isBoundary();
};
