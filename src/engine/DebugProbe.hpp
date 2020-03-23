#pragma once
#include "Actor.hpp"
#include "raylib.h"
#include "./components/BidimensionalComponent.hpp"

class DebugProbe {
 private:
    Actor* mMainActor;
    BidimensionalComponent* mMainActorPosition;
    EventManager* mManager;
 public:
    explicit DebugProbe(Actor* mainActor, EventManager* manager);
    void display();
};
