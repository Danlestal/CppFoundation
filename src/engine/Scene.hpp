#pragma once
#include <list>

#include "Actor.hpp"



class Scene {
 private:
    std::list<Actor*> mActors;
 public:
    void addActor(Actor* newActor);
    std::list<Actor*>  getActors();
    Actor* getActor(long mActorId);
    void removeActor(long mActorId);
};
