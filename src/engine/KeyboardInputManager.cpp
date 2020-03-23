#include "KeyboardInputManager.hpp"

#include "raylib.h"
#include "Vector2d.hpp"
#include "./events/OrderActorToMoveEventData.hpp"

KeyboardInputManager::KeyboardInputManager(long playerId, EventManager* eventManager) {
    mPlayerId = playerId;
    mEventManager = eventManager;
}

void KeyboardInputManager::proccessInput() {
    OrderActorToMoveEventData* movement = NULL;

    if (IsKeyDown(KEY_RIGHT)) movement = new OrderActorToMoveEventData(mPlayerId, Vector2D(1, 0));
    if (IsKeyDown(KEY_LEFT)) movement = new OrderActorToMoveEventData(mPlayerId, Vector2D(-1, 0));
    if (IsKeyDown(KEY_UP)) movement = new OrderActorToMoveEventData(mPlayerId, Vector2D(0, -1));
    if (IsKeyDown(KEY_DOWN)) movement = new OrderActorToMoveEventData(mPlayerId, Vector2D(0, 1));

    if (movement) {
        mEventManager->queueEvent(movement);
    }
}
