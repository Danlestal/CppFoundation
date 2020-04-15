#pragma once
#include "./events/EventManager.hpp"

class KeyboardInputManager {
 private:
    EventManager* mEventManager;
    long mPlayerId;
    bool mEditorMode;
 public:
    explicit KeyboardInputManager(EventManager* eventManager);
    void proccessPlayerInput(long playerId);
};
