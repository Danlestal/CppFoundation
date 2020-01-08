#pragma once
#include "./events/EventManager.hpp"

class KeyboardInputManager {
 private:
    EventManager* mEventManager;
 public:
    explicit KeyboardInputManager(EventManager* eventManager);
    void proccessInput();
};
