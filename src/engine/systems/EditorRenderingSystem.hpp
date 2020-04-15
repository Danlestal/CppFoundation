#pragma once
#include "../Actor.hpp"
#include "raylib.h"
#include "raygui.h"



class EditorRenderingSystem {
 private:
    Actor* mCamera;
    Vector2 mOffset;
 public:
    explicit EditorRenderingSystem(Actor* camera, Vector2 cameraOffset);
    void draw();
};
