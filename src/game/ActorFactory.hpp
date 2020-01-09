#pragma once
#include "../engine/Actor.hpp"
#include "../engine/IdentifierProvider.hpp"
#include "../engine/events/EventManager.hpp"

class ActorFactory {
 private:
    EventManager* mEventManager;
    IdentifierProvider* mIdProvider;
 public:
    ActorFactory(IdentifierProvider* provider, EventManager* eventManager);
    Actor* createInvader();
    Actor* createPlayerSpaceship();
};
