#include "ActorFactory.hpp"
#include "../engine/Vector2d.hpp"

#include "../engine/components/Component.hpp"
#include "../engine/components/LifeComponent.hpp"
#include "../engine/components/BidimensionalComponent.hpp"
#include "../engine/components/GunComponent.hpp"
#include "../engine/components/BoundingSquareComponent.hpp"

#include "../engine/components/graphics/GraphicComponent.hpp"
#include "../engine/components/graphics/CircleGraphicComponent.hpp"
#include "../engine/components/graphics/SquareGraphicComponent.hpp"
#include "../engine/components/graphics/SpaceshipTextureComponent.hpp"
#include "../engine/components/graphics/BulletTextureComponent.hpp"
#include "../engine/components/graphics/ScoreBoardComponent.hpp"
#include "../engine/components/CameraComponent.hpp"

#include "../engine/components/behaviours/InvaderBehaviourComponent.hpp"
#include "../engine/components/behaviours/BulletBehaviourComponent.hpp"


#include "../engine/events/DestroyActorEventData.hpp"
#include "../engine/events/SpawnBulletEventData.hpp"

ActorFactory::ActorFactory(IdentifierProvider* provider,
                            Scene* scene,
                            EventManager* evtManager,
                            ResourceManager resources,
                            Vector2D gameResolution) {
    mIdProvider = provider;
    mScene = scene;
    mResources = resources;
    mEventManager = evtManager;
    mGameResolution = gameResolution;
    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                            &ActorFactory::destroyActor),
                                                            "DestroyActorEventDataType");

    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                        &ActorFactory::spawnBullet),
                                                        "SpawnBulletEventDataType");

    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                    &ActorFactory::spawnNewInvader),
                                                    "InvaderKilledEventDataType");
}

Actor* ActorFactory::createScoreboard() {
    Actor* scoreBoard = new Actor(mIdProvider->getUID());
    BidimensionalComponent* biComponent = new BidimensionalComponent(
                                                        scoreBoard->getId(),
                                                        Vector2D(mGameResolution.x - 150, mGameResolution.y - 80),
                                                        mEventManager);
    scoreBoard->addComponent(biComponent);
    scoreBoard->addComponent(new ScoreBoardComponent(mEventManager));
    return scoreBoard;
}

Actor* ActorFactory::createInvader() {
    Actor* invader = new Actor(mIdProvider->getUID());
    BidimensionalComponent* biComponent = new BidimensionalComponent(invader->getId(), Vector2D(50, 50), mEventManager);
    invader->addComponent(biComponent);
    invader->addComponent(new CircleGraphicComponent());
    invader->addComponent(new InvaderBehaviourComponent(invader->getId(), mEventManager));
    invader->addComponent(new BoundingSquareComponent(Vector2D(10, 10)));
    return invader;
}

Actor* ActorFactory::createPlayerSpaceship() {
    Actor* spaceShip = new Actor(mIdProvider->getUID());
    Vector2D initialVector = Vector2D(mGameResolution.x / 2, mGameResolution.y -150);
    spaceShip->addComponent(new BidimensionalComponent(spaceShip->getId(), initialVector, mEventManager));
    spaceShip->addComponent(new BoundingSquareComponent(Vector2D(30, 30)));
    spaceShip->addComponent(new GunComponent(spaceShip->getId(), initialVector, mEventManager));
    spaceShip->addComponent(new LifeComponent(spaceShip->getId(), 3, mEventManager));
    TextureMap* textureMap = new XenonTextureMap(mResources.getTexture("xenon2_textures"));
    spaceShip->addComponent(new SpaceshipTextureComponent(spaceShip->getId(), textureMap, mEventManager));
    return spaceShip;
}

Actor* ActorFactory::createCameraComponent(Camera2D* rayCamera) {
    Actor* camera = new Actor(mIdProvider->getUID());
    Vector2D initialVector = Vector2D(mGameResolution.x / 2, mGameResolution.y / 2);
    camera->addComponent(new CameraComponent(rayCamera, mEventManager, initialVector));
    return camera;
}

Actor* ActorFactory::createBullet(Vector2D initialPosition) {
    Actor* bullet = new Actor(mIdProvider->getUID());
    BidimensionalComponent* biComponent =
    new BidimensionalComponent(bullet->getId(), initialPosition, mEventManager);
    bullet->addComponent(biComponent);
    TextureMap* textureMap = new XenonTextureMap(mResources.getTexture("xenon2_textures"));

    bullet->addComponent(new BulletTextureComponent(bullet->getId(), textureMap, mEventManager));
    bullet->addComponent(new BoundingSquareComponent(Vector2D(16, 16)));
    bullet->addComponent(new BulletBehaviourComponent(bullet->getId(), mEventManager));
    return bullet;
}

std::vector<Actor*> ActorFactory::createBoundaries() {
    float boardWidth = mGameResolution.x -100;
    float boardHeight = mGameResolution.y -100;

    Actor* leftBoundary = new Actor(mIdProvider->getUID());
    leftBoundary->addComponent(new BidimensionalComponent(leftBoundary->getId(), Vector2D(), mEventManager));
    leftBoundary->addComponent(new BoundingSquareComponent(Vector2D(2, boardHeight), true));
    leftBoundary->addComponent(new SquareGraphicComponent(2, boardHeight));

    Actor* rightBoundary = new Actor(mIdProvider->getUID());
    rightBoundary->addComponent(new BidimensionalComponent(rightBoundary->getId(),
                                                            Vector2D(boardWidth, 0),
                                                            mEventManager));
    rightBoundary->addComponent(new BoundingSquareComponent(Vector2D(2, boardHeight), true));
    rightBoundary->addComponent(new SquareGraphicComponent(2, boardHeight));

    Actor* bottomBoundary = new Actor(mIdProvider->getUID());
    bottomBoundary->addComponent(new BidimensionalComponent(bottomBoundary->getId(),
                                                            Vector2D(0, boardHeight),
                                                            mEventManager));
    bottomBoundary->addComponent(new BoundingSquareComponent(Vector2D(boardWidth, 2), true));
    bottomBoundary->addComponent(new SquareGraphicComponent(boardWidth, 2));


    Actor* upperBoundary = new Actor(mIdProvider->getUID());
    upperBoundary->addComponent(new BidimensionalComponent(upperBoundary->getId(), Vector2D(0, 5), mEventManager));
    upperBoundary->addComponent(new BoundingSquareComponent(Vector2D(boardWidth, 2), true));
    upperBoundary->addComponent(new SquareGraphicComponent(boardWidth, 2));

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

void ActorFactory::spawnNewInvader(IEventData* killedInvaderEvent) {
    mScene->addActor(createInvader());
}
