#include "KeyboardInputManager.hpp"

#include <memory>
#include <vector>
#include "raylib.h"
#include "./events/MovePlayerEventData.hpp"

KeyboardInputManager::KeyboardInputManager(EventManager* eventManager) {
    mEventManager = eventManager;
}

void KeyboardInputManager::proccessInput() {
    MovePlayerEventData* movement = NULL;

    if (IsKeyDown(KEY_RIGHT)) movement = new MovePlayerEventData(1, 0);
    if (IsKeyDown(KEY_LEFT)) movement = new MovePlayerEventData(-1, 0);
    if (IsKeyDown(KEY_UP)) movement = new MovePlayerEventData(0, -1);
    if (IsKeyDown(KEY_DOWN)) movement = new MovePlayerEventData(0, 1);

    if (!movement) {
        return;
    }
    else {
         mEventManager->queueEvent(movement);
    }
}
