#include "ActorFactory.hpp"
#include "../engine/Vector2d.hpp"
#include "../engine/components/Component.hpp"
#include "../engine/components/LifeComponent.hpp"
#include "../engine/components/GraphicComponent.hpp"
#include "../engine/components/CircleGraphicComponent.hpp"
#include "../engine/components/SquareGraphicComponent.hpp"
#include "../engine/components/BidimensionalComponent.hpp"
#include "../engine/components/BehaviourComponent.hpp"
#include "../engine/components/BoundingSquareComponent.hpp"
#include "../engine/components/TextureComponent.hpp"

ActorFactory::ActorFactory(IdentifierProvider* provider, EventManager* eventManager) {
    mIdProvider = provider;
    mEventManager = eventManager;
}

Actor* ActorFactory::createInvader() {
    Actor* invader = new Actor(mIdProvider->getUID());
    BidimensionalComponent* biComponent = new BidimensionalComponent(invader->getId(), Vector2D(), mEventManager);
    mEventManager->addListener(fastdelegate::MakeDelegate(biComponent,
                                                            &BidimensionalComponent::updatePosition),
                                                            "OrderActorToMoveEventDataType");
    invader->addComponent(biComponent);
    invader->addComponent(new CircleGraphicComponent());

    invader->addComponent(new BehaviourComponent(invader->getId(),
                                                mEventManager));
    invader->addComponent(new BoundingSquareComponent(Vector2D(10, 10)));
    return invader;
}

Actor* ActorFactory::createPlayerSpaceship() {
    Actor* spaceShip = new Actor(mIdProvider->getUID());
    BidimensionalComponent* biComponent =
    new BidimensionalComponent(spaceShip->getId(), Vector2D(200, 395), mEventManager);
    mEventManager->addListener(fastdelegate::MakeDelegate(biComponent,
                                                            &BidimensionalComponent::updatePosition),
                                                            "OrderActorToMoveEventDataType");

    mEventManager->addListener(fastdelegate::MakeDelegate(biComponent,
                                                            &BidimensionalComponent::receiveCollision),
                                                            "ActorCollidesEventDataType");

    spaceShip->addComponent(biComponent);
    spaceShip->addComponent(new SquareGraphicComponent(10, 10));
    Texture2D scarfy = LoadTexture("./resources/xenon2_sprites.png");
    spaceShip->addComponent(new TextureComponent(10, 10, scarfy));
    spaceShip->addComponent(new BoundingSquareComponent(Vector2D(10, 10)));
    return spaceShip;
}


std::vector<Actor*> ActorFactory::createBoundaries(int boardWith, int boardHeight) {
    Actor* leftBoundary = new Actor(mIdProvider->getUID());
    leftBoundary->addComponent(new BidimensionalComponent(leftBoundary->getId(), Vector2D(), mEventManager));
    leftBoundary->addComponent(new BoundingSquareComponent(Vector2D(2, 600)));
    leftBoundary->addComponent(new SquareGraphicComponent(2, 600));

    Actor* rightBoundary = new Actor(mIdProvider->getUID());
    rightBoundary->addComponent(new BidimensionalComponent(rightBoundary->getId(), Vector2D(boardWith, 0), mEventManager));
    rightBoundary->addComponent(new BoundingSquareComponent(Vector2D(2, 600)));
    rightBoundary->addComponent(new SquareGraphicComponent(2, 600));

    Actor* bottomBoundary = new Actor(mIdProvider->getUID());
    bottomBoundary->addComponent(new BidimensionalComponent(bottomBoundary->getId(), Vector2D(0, boardHeight), mEventManager));
    bottomBoundary->addComponent(new BoundingSquareComponent(Vector2D(boardWith, 2)));
    bottomBoundary->addComponent(new SquareGraphicComponent(boardWith, 2));

    return std::vector<Actor*>{ leftBoundary, rightBoundary, bottomBoundary};
}
