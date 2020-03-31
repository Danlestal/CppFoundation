#pragma once
#include <list>

#include "Actor.hpp"
#include "./events/EventManager.hpp"
#include "./events/AddActorEventData.hpp"


class Scene {
 private:
   std::list<Actor*> mActors;
   EventManager* mEventManager;
 public:
   explicit Scene(EventManager* eventManager);
   void addActor(Actor* newActor);
   std::list<Actor*>  getActors();
   Actor* getActor(long mActorId);
   void removeActor(long mActorId);
   EventManager* getEventManager(); 
};
