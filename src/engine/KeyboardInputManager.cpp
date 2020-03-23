#include "KeyboardInputManager.hpp"

#include "raylib.h"
#include "Vector2d.hpp"
#include "./events/MoveActorEventData.hpp"

KeyboardInputManager::KeyboardInputManager(long playerId, EventManager* eventManager) {
    mPlayerId = playerId;
    mEventManager = eventManager;
}

void KeyboardInputManager::proccessInput() {
    MoveActorEventData* movement = NULL;

    if (IsKeyDown(KEY_RIGHT)) movement = new MoveActorEventData(mPlayerId, Vector2D(1, 0));
    if (IsKeyDown(KEY_LEFT)) movement = new MoveActorEventData(mPlayerId, Vector2D(-1, 0));
    if (IsKeyDown(KEY_UP)) movement = new MoveActorEventData(mPlayerId, Vector2D(0, -1));
    if (IsKeyDown(KEY_DOWN)) movement = new MoveActorEventData(mPlayerId, Vector2D(0, 1));

    if (movement) {
        mEventManager->queueEvent(movement);
    }
}
