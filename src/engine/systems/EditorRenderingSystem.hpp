#pragma once
#include "../Actor.hpp"
#include "raylib.h"

class EditorRenderingSystem {
 private:
    Actor* mCamera;
 public:
    explicit EditorRenderingSystem(Actor* camera);
    void draw();
};
