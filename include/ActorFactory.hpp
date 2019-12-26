#pragma once
#include "Actor.hpp"
#include "Invader.hpp"
#include "IdentifierProvider.hpp"

class ActorFactory {
 private:
    IdentifierProvider* mIdProvider;
 public:
    ActorFactory(IdentifierProvider* provider);
    Invader* createInvader();
    Actor* createPlayerSpaceship();

};