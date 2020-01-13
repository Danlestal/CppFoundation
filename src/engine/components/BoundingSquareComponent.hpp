#pragma once
#include <string>
#include "Component.hpp"

class BoundingSquareComponent : public Component {
 private:
  int mWidth;
  int mHeight;
 public:
    BoundingSquareComponent(int width, int height) {
        mWidth = width;
        mHeight = height;
    }
    std::string getType() {
            return "BoundingSquareComponent";
    }
};

