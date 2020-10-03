#pragma once
#include <vector>
#include "../engine/Actor.hpp"
#include "../engine/Vector2d.hpp"
#include "../engine/IdentifierProvider.hpp"
#include "../engine/Scene.hpp"
#include "../engine/events/EventManager.hpp"
#include "../engine/ResourceManager.hpp"

class ActorFactory {
 private:
    Scene* mScene;
    IdentifierProvider* mIdProvider;
    EventManager* mEventManager;
    ResourceManager mResources;
    Vector2D mGameResolution;
 public:
    ActorFactory(IdentifierProvider* provider,
                  Scene* eventManager,
                  EventManager* evtManager,
                  ResourceManager resources,
                  Vector2D gameResolution);
    Actor*  createScoreboard();
    Actor* createInvader(Vector2D position);
    Actor* createWallRock(Vector2D position, Vector2D dimensions);
    Actor* createPlayerSpaceship();
    Actor* createCameraComponent(Camera2D* rayCamera);
    Actor* createBullet(Vector2D initialPosition);
    std::vector<Actor*> createBoundaries();


    void destroyActor(IEventData* spawnActorEventData);
    void spawnBullet(IEventData* spawnBulletData);
};
