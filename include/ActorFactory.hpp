#pragma once
#include "Actor.hpp"
#include "Invader.hpp"
#include "IdentifierProvider.hpp"
#include "../src/engine/events/EventManager.hpp"

class ActorFactory {
 private:
   EventManager* mEventManager;
   IdentifierProvider* mIdProvider;
 public:
    ActorFactory(IdentifierProvider* provider, EventManager* eventManager);
    Invader* createInvader();
    Actor* createPlayerSpaceship();

};