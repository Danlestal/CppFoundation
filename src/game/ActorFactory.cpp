#include "ActorFactory.hpp"

ActorFactory::ActorFactory(IdentifierProvider* provider) {
    mIdProvider = provider;
}

Actor* ActorFactory::createInvader() {
    Actor* invader = new Actor(mIdProvider->getUID());
    return invader;
}

Actor* ActorFactory::createPlayerSpaceship() {
    Actor* spaceShip = new Actor(mIdProvider->getUID());
    return spaceShip;
}
