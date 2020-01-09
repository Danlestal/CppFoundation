#include "ActorFactory.hpp"
#include "Invader.hpp"
#include "../engine/components/Component.hpp"
#include "../engine/components/LifeComponent.hpp"
#include "../engine/components/GraphicComponent.hpp"
#include "../engine/components/GraphicComponentWithTexture.hpp"

ActorFactory::ActorFactory(IdentifierProvider* provider, EventManager* eventManager) {
    mIdProvider = provider;
    mEventManager = eventManager;
}

Invader* ActorFactory::createInvader() {
    Actor* invader = new Actor(mIdProvider->getUID());
    invader->addComponent(new LifeComponent(10));
    invader->addComponent(new GraphicComponentWithTexture(mEventManager));


    return new Invader(invader);
}

Actor* ActorFactory::createPlayerSpaceship() {
    Actor* spaceShip = new Actor(mIdProvider->getUID());
    return spaceShip;
}
