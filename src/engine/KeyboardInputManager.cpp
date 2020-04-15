#include "KeyboardInputManager.hpp"

#include "raylib.h"
#include "Vector2d.hpp"
#include "./events/OrderActorToMoveEventData.hpp"
#include "./events/OrderActorToShotEventData.hpp"

KeyboardInputManager::KeyboardInputManager(EventManager* eventManager) {
    mEventManager = eventManager;
    mEditorMode = false;
}

void KeyboardInputManager::emitMovementOrdersToActor(long actorId) {
    OrderActorToMoveEventData* movement = NULL;
    Vector2D vector = Vector2D(0, 0);

    if (IsKeyDown(KEY_RIGHT)) vector += Vector2D(1, 0);
    if (IsKeyDown(KEY_LEFT)) vector += Vector2D(-1, 0);
    if (IsKeyDown(KEY_UP)) vector += Vector2D(0, -1);
    if (IsKeyDown(KEY_DOWN)) vector += Vector2D(0, 1);

    if (vector.x != 0 || vector.y != 0) {
        mEventManager->queueEvent(new OrderActorToMoveEventData(actorId, vector));
    }
}

void KeyboardInputManager::proccessEditorInput(long cameraId) {
    emitMovementOrdersToActor(cameraId);
}



void KeyboardInputManager::proccessPlayerInput(long playerId) {
    emitMovementOrdersToActor(playerId);
    if (IsKeyDown(KEY_SPACE)) {
        mEventManager->queueEvent(new OrderActorToShotEventData(playerId));
    }
}
