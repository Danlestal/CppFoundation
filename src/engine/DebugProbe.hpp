#pragma once
#include "Actor.hpp"
#include "raylib.h"
#include "./components/BidimensionalComponent.hpp"

class DebugProbe {
 private:
    Actor* mMainActor;
    BidimensionalComponent* mMainActorPosition;
 public:
    explicit DebugProbe(Actor* mainActor);
    void display();
};
