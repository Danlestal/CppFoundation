#include "ActorFactory.hpp"
#include "Component.hpp"
#include "Invader.hpp"
#include "../engine/components/LifeComponent.hpp"
#include "../engine/components/GraphicComponent.hpp"

ActorFactory::ActorFactory(IdentifierProvider* provider) {
    mIdProvider = provider;
}

Invader* ActorFactory::createInvader() {
    Actor* invader = new Actor(mIdProvider->getUID());
    invader->addComponent(new LifeComponent(10));
    invader->addComponent(new GraphicComponent());


    return new Invader(invader);
}

Actor* ActorFactory::createPlayerSpaceship() {
    Actor* spaceShip = new Actor(mIdProvider->getUID());
    return spaceShip;
}
