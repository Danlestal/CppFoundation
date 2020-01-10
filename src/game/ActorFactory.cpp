#include "ActorFactory.hpp"
#include "../engine/components/Component.hpp"
#include "../engine/components/LifeComponent.hpp"
#include "../engine/components/GraphicComponent.hpp"
#include "../engine/components/CircleGraphicComponent.hpp"
#include "../engine/components/SquareGraphicComponent.hpp"
#include "../engine/components/BidimensionalComponent.hpp"
#include "../engine/components/BehaviourComponent.hpp"

ActorFactory::ActorFactory(IdentifierProvider* provider, EventManager* eventManager) {
    mIdProvider = provider;
    mEventManager = eventManager;
}

Actor* ActorFactory::createInvader() {
    Actor* invader = new Actor(mIdProvider->getUID());
    BidimensionalComponent* biComponent = new BidimensionalComponent(invader->getId(), 0, 0);
    mEventManager->addListener(fastdelegate::MakeDelegate(biComponent,
                                                            &BidimensionalComponent::updatePosition),
                                                            "MoveActorEventDataType");
    invader->addComponent(biComponent);
    invader->addComponent(new CircleGraphicComponent(mEventManager));

    invader->addComponent(new BehaviourComponent(invader->getId(),
                                                mEventManager));
    return invader;
}

Actor* ActorFactory::createPlayerSpaceship() {
    Actor* spaceShip = new Actor(mIdProvider->getUID());
    BidimensionalComponent* biComponent = new BidimensionalComponent(spaceShip->getId(), 40, 40);
    mEventManager->addListener(fastdelegate::MakeDelegate(biComponent,
                                                            &BidimensionalComponent::updatePosition),
                                                            "MoveActorEventDataType");
    spaceShip->addComponent(biComponent);
    spaceShip->addComponent(new SquareGraphicComponent(mEventManager));
    return spaceShip;
}
