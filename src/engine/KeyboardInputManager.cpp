#include "KeyboardInputManager.hpp"
#include "raylib.h"

void KeyboardInputManager::proccessInput() {
    if (IsKeyDown(KEY_RIGHT)) TraceLog(LOG_INFO, "RIGHT");
    if (IsKeyDown(KEY_LEFT)) TraceLog(LOG_INFO, "LEFT");
    if (IsKeyDown(KEY_UP)) TraceLog(LOG_INFO, "UP");
    if (IsKeyDown(KEY_DOWN)) TraceLog(LOG_INFO, "DOWN");
}
