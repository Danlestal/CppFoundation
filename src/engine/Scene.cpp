#include "Scene.hpp"

void Scene::addActor(Actor* actor) {
    mActors.push_back(actor);
}

void Scene::removeActor(long mActorId) {
    Actor* actorToRemove = getActor(mActorId);
    mActors.remove(actorToRemove);
    delete actorToRemove;
}

Actor* Scene::getActor(long actorId) {
    for (auto it = mActors.begin(); it != mActors.end(); ++it) {
        Actor* actor = (*it);
        if (actor->getId() == actorId) {
            return actor;
        }
    }

    return nullptr;
}

std::list<Actor*> Scene::getActors() {
    return mActors;
}

