#pragma once
#include "Actor.hpp"
#include "IdentifierProvider.hpp"

class ActorFactory {
 private:
    IdentifierProvider* mIdProvider;
 public:
    ActorFactory(IdentifierProvider* provider);
    Actor* createInvader();
    Actor* createPlayerSpaceship();

};