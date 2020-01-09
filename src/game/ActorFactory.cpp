#include "ActorFactory.hpp"
#include "../engine/components/Component.hpp"
#include "../engine/components/LifeComponent.hpp"
#include "../engine/components/GraphicComponent.hpp"
#include "../engine/components/CircleGraphicComponent.hpp"
#include "../engine/components/SquareGraphicComponent.hpp"

ActorFactory::ActorFactory(IdentifierProvider* provider, EventManager* eventManager) {
    mIdProvider = provider;
    mEventManager = eventManager;
}

Actor* ActorFactory::createInvader() {
    Actor* invader = new Actor(mIdProvider->getUID());
    invader->addComponent(new LifeComponent(10));
    invader->addComponent(new CircleGraphicComponent(mEventManager));
    return invader;
}

Actor* ActorFactory::createPlayerSpaceship() {
    Actor* spaceShip = new Actor(mIdProvider->getUID());
    spaceShip->addComponent(new SquareGraphicComponent(mEventManager));
    return spaceShip;
}
