#pragma once
#include <vector>

#include "Actor.hpp"
#include "events/EventManager.hpp"


class Scene {
 private:
    std::vector<Actor*> mActors;
    EventManager* mEvtManager;
 public:
    explicit Scene(EventManager* evtManager);
    void addActor(Actor* newActor);
    std::vector<Actor*> getActors();
};
