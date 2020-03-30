#pragma once
#include <vector>
#include "../engine/Actor.hpp"
#include "../engine/Vector2d.hpp"
#include "../engine/IdentifierProvider.hpp"
#include "../engine/Scene.hpp"
#include "../engine/events/EventManager.hpp"

class ActorFactory {
 private:
    Scene* mScene;
    IdentifierProvider* mIdProvider;
    EventManager* mEventManager;
 public:
    ActorFactory(IdentifierProvider* provider, Scene* eventManager, EventManager* evtManager);
    Actor* createInvader();
    Actor* createPlayerSpaceship();
    Actor* createBullet(Vector2D initialPosition);
    std::vector<Actor*> createBoundaries(int boardWith, int boardHeight);


    void destroyActor(IEventData* spawnActorEventData);
    void spawnBullet(IEventData* spawnBulletData);
};
