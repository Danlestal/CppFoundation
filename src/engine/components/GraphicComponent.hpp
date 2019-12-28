#pragma once
#include <string>
#include "raylib.h"
#include "Component.hpp"

class GraphicComponent : public Component {
 public:
    void draw(int posX, int posY);
    std::string getType();
};
