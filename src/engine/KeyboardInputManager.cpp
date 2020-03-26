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
    Vector2D vector = Vector2D(0, 0);

    if (IsKeyDown(KEY_RIGHT)) vector += Vector2D(1, 0);
    if (IsKeyDown(KEY_LEFT)) vector += Vector2D(-1, 0);
    if (IsKeyDown(KEY_UP)) vector += Vector2D(0, -1);
    if (IsKeyDown(KEY_DOWN)) vector += Vector2D(0, 1);

    if (vector.x != 0 || vector.y != 0) {
        mEventManager->queueEvent(new OrderActorToMoveEventData(mPlayerId, vector));
    }
}
