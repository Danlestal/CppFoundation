#pragma once
#include "Actor.hpp"
class Invader {
 private:
    Actor* mActor;

 public:
    Invader(Actor* actor);
    int getLife();
    int isAlive();
};
