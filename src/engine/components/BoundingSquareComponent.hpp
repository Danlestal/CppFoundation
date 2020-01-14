#pragma once
#include <string>
#include "Component.hpp"
#include "../Vector2d.hpp"

class BoundingSquareComponent : public Component {
 private:
  Vector2D mDimensions;
 public:
    explicit BoundingSquareComponent(Vector2D dimensions) {
        mDimensions = dimensions;
    }
    std::string getType() {
            return "BoundingSquareComponent";
    }
};

