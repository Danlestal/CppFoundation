#include "ActorFactory.hpp"
#include "Component.hpp"
#include "Invader.hpp"
#include "../engine/components/LifeComponent.hpp"

ActorFactory::ActorFactory(IdentifierProvider* provider) {
    mIdProvider = provider;
}

Invader* ActorFactory::createInvader() {
    Actor* invader = new Actor(mIdProvider->getUID());
    Component* component = new LifeComponent(10);
    invader->addComponent(component);
    return new Invader(invader);
}

Actor* ActorFactory::createPlayerSpaceship() {
    Actor* spaceShip = new Actor(mIdProvider->getUID());
    return spaceShip;
}
