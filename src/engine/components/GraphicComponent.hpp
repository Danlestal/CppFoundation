#pragma once
#include <string>
#include "raylib.h"
#include "Component.hpp"

class GraphicComponent : public Component {
 private:
    int mPosX;
    int mPosY;
 public:
    void draw();
    std::string getType();
};
