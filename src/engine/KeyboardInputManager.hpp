#pragma once
#include "./events/EventManager.hpp"

class KeyboardInputManager {
 private:
    EventManager* mEventManager;
    long mPlayerId;
 public:
    explicit KeyboardInputManager(long playerId, EventManager* eventManager);
    void proccessInput();
};
