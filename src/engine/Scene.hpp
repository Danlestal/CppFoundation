#pragma once
#include <list>

#include "Actor.hpp"
#include "events/EventManager.hpp"


class Scene {
 private:
    std::list<Actor*> mActors;
    EventManager* mEvtManager;
 public:
    explicit Scene(EventManager* evtManager);
    void addActor(Actor* newActor);
    std::list<Actor*>  getActors();
};
