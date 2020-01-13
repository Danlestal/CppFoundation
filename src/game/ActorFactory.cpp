#include "ActorFactory.hpp"
#include "../engine/components/Component.hpp"
#include "../engine/components/LifeComponent.hpp"
#include "../engine/components/GraphicComponent.hpp"
#include "../engine/components/CircleGraphicComponent.hpp"
#include "../engine/components/SquareGraphicComponent.hpp"
#include "../engine/components/BidimensionalComponent.hpp"
#include "../engine/components/BehaviourComponent.hpp"
#include "../engine/components/BoundingSquareComponent.hpp"

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
    invader->addComponent(new BoundingSquareComponent(10, 10));
    return invader;
}

Actor* ActorFactory::createPlayerSpaceship() {
    Actor* spaceShip = new Actor(mIdProvider->getUID());
    BidimensionalComponent* biComponent = new BidimensionalComponent(spaceShip->getId(), 200, 420);
    mEventManager->addListener(fastdelegate::MakeDelegate(biComponent,
                                                            &BidimensionalComponent::updatePosition),
                                                            "MoveActorEventDataType");
    spaceShip->addComponent(biComponent);
    spaceShip->addComponent(new SquareGraphicComponent(10, 10, mEventManager));
    spaceShip->addComponent(new BoundingSquareComponent(10, 10));
    return spaceShip;
}


std::vector<Actor*> ActorFactory::createBoundaries(int boardWith, int boardHeight) {
    Actor* leftBoundary = new Actor(mIdProvider->getUID());
    leftBoundary->addComponent(new BidimensionalComponent(leftBoundary->getId(), 0, 0));
    leftBoundary->addComponent(new BoundingSquareComponent(2, 600));
    leftBoundary->addComponent(new SquareGraphicComponent(2, 600, mEventManager));

    Actor* rightBoundary = new Actor(mIdProvider->getUID());
    rightBoundary->addComponent(new BidimensionalComponent(rightBoundary->getId(), boardWith, 0));
    rightBoundary->addComponent(new BoundingSquareComponent(2, 600));
    rightBoundary->addComponent(new SquareGraphicComponent(2, 600, mEventManager));

    Actor* bottomBoundary = new Actor(mIdProvider->getUID());
    bottomBoundary->addComponent(new BidimensionalComponent(bottomBoundary->getId(), 0, boardHeight));
    bottomBoundary->addComponent(new BoundingSquareComponent(boardWith, 2));
    bottomBoundary->addComponent(new SquareGraphicComponent(boardWith, 2, mEventManager));

    return std::vector<Actor*>{ leftBoundary, rightBoundary, bottomBoundary};
}
