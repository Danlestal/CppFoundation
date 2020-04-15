#pragma once
#include "./events/EventManager.hpp"

class KeyboardInputManager {
 private:
    EventManager* mEventManager;
    long mPlayerId;
    bool mEditorMode;
    void emitMovementOrdersToActor(long actorId);
 public:
    explicit KeyboardInputManager(EventManager* eventManager);
    void proccessPlayerInput(long playerId);
    void proccessEditorInput(long cameraId);
};
