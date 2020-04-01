#include "ActorFactory.hpp"
#include "../engine/Vector2d.hpp"
#include "../engine/components/Component.hpp"
#include "../engine/components/LifeComponent.hpp"
#include "../engine/components/graphics/GraphicComponent.hpp"
#include "../engine/components/graphics/CircleGraphicComponent.hpp"
#include "../engine/components/graphics/SquareGraphicComponent.hpp"
#include "../engine/components/graphics/AnimatedTextureComponent.hpp"
#include "../engine/components/BidimensionalComponent.hpp"

#include "../engine/components/behaviours/InvaderBehaviourComponent.hpp"
#include "../engine/components/BoundingSquareComponent.hpp"

#include "../engine/components/GunComponent.hpp"

#include "../engine/components/behaviours/BulletBehaviourComponent.hpp"

#include "../engine/events/DestroyActorEventData.hpp"
#include "../engine/events/SpawnBulletEventData.hpp"



ActorFactory::ActorFactory( IdentifierProvider* provider,
                            Scene* scene,
                            EventManager* evtManager) {
    mIdProvider = provider;
    mScene = scene;
    mEventManager = evtManager;
    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                            &ActorFactory::destroyActor),
                                                            "DestroyActorEventDataType");

    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                        &ActorFactory::spawnBullet),
                                                        "SpawnBulletEventDataType");
}

Actor* ActorFactory::createInvader() {
    Actor* invader = new Actor(mIdProvider->getUID());
    BidimensionalComponent* biComponent = new BidimensionalComponent(invader->getId(), Vector2D(), mEventManager);
    mEventManager->addListener(fastdelegate::MakeDelegate(biComponent,
                                                            &BidimensionalComponent::updatePosition),
                                                            "OrderActorToMoveEventDataType");
    invader->addComponent(biComponent);
    invader->addComponent(new CircleGraphicComponent());

    invader->addComponent(new InvaderBehaviourComponent(invader->getId(), mEventManager));
    invader->addComponent(new BoundingSquareComponent(Vector2D(10, 10)));
    return invader;
}

Actor* ActorFactory::createPlayerSpaceship() {
    Actor* spaceShip = new Actor(mIdProvider->getUID());
    Vector2D initialVector = Vector2D(200, 350);
    spaceShip->addComponent(new BidimensionalComponent(spaceShip->getId(), initialVector, mEventManager));
    spaceShip->addComponent(new BoundingSquareComponent(Vector2D(30, 30)));
    spaceShip->addComponent(new GunComponent(spaceShip->getId(), initialVector, mEventManager));
    Texture2D xenonTexture = LoadTexture("./resources/xenon2_sprites.png");
    TextureMap* textureMap = new XenonTextureMap(xenonTexture);
    spaceShip->addComponent(new AnimatedTextureComponent(spaceShip->getId(), textureMap, mEventManager));
    return spaceShip;
}

Actor* ActorFactory::createBullet(Vector2D initialPosition) {
    Actor* bullet = new Actor(mIdProvider->getUID());
    BidimensionalComponent* biComponent =
    new BidimensionalComponent(bullet->getId(), initialPosition, mEventManager);
    bullet->addComponent(biComponent);
    bullet->addComponent(new SquareGraphicComponent(20, 20));
    bullet->addComponent(new BoundingSquareComponent(Vector2D(20, 20)));
    bullet->addComponent(new BulletBehaviourComponent(bullet->getId(), mEventManager));
    return bullet;
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


    Actor* upperBoundary = new Actor(mIdProvider->getUID());
    upperBoundary->addComponent(new BidimensionalComponent(upperBoundary->getId(), Vector2D(0, 5), mEventManager));
    upperBoundary->addComponent(new BoundingSquareComponent(Vector2D(boardWith, 2)));
    upperBoundary->addComponent(new SquareGraphicComponent(boardWith, 2));

    return std::vector<Actor*>{ leftBoundary, rightBoundary, bottomBoundary, upperBoundary};
}

void ActorFactory::destroyActor(IEventData* destroyActorEventData) {
    DestroyActorEventData* destroyEvent = reinterpret_cast<DestroyActorEventData*>(destroyActorEventData);
    mScene->removeActor(destroyEvent->getActorId());
}

void ActorFactory::spawnBullet(IEventData* spawnBulletData) {
    SpawnBulletEventData* spawnEvent = reinterpret_cast<SpawnBulletEventData*>(spawnBulletData);
    Actor* bullet = createBullet(spawnEvent->getInitialPosition());
    mScene->addActor(bullet);
}
