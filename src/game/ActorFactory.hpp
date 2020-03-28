#pragma once
#include <vector>
#include "../engine/Actor.hpp"
#include "../engine/IdentifierProvider.hpp"
#include "../engine/Scene.hpp"

class ActorFactory {
 private:
    Scene* mScene;
    IdentifierProvider* mIdProvider;
    EventManager* mEventManager;
 public:
    ActorFactory(IdentifierProvider* provider, Scene* eventManager);
    Actor* createInvader();
    Actor* createPlayerSpaceship();
    Actor* createBullet(Vector2D initialPosition);
    std::vector<Actor*> createBoundaries(int boardWith, int boardHeight);
};
