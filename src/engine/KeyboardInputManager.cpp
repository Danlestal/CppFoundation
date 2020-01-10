#include "KeyboardInputManager.hpp"

#include <memory>
#include <vector>
#include "raylib.h"
#include "./events/MoveActorEventData.hpp"

KeyboardInputManager::KeyboardInputManager(long playerId, EventManager* eventManager) {
    mPlayerId = playerId;
    mEventManager = eventManager;
}

void KeyboardInputManager::proccessInput() {
    MoveActorEventData* movement = NULL;

    if (IsKeyDown(KEY_RIGHT)) movement = new MoveActorEventData(mPlayerId, 1, 0);
    if (IsKeyDown(KEY_LEFT)) movement = new MoveActorEventData(mPlayerId, -1, 0);
    if (IsKeyDown(KEY_UP)) movement = new MoveActorEventData(mPlayerId, 0, -1);
    if (IsKeyDown(KEY_DOWN)) movement = new MoveActorEventData(mPlayerId, 0, 1);

    if (!movement) {
        return;
    }
    else {
         mEventManager->queueEvent(movement);
    }
}
