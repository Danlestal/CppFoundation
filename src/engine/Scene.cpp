#include "Scene.hpp"

Scene::Scene(EventManager* evtManager) {
    mEvtManager = evtManager;
}

void Scene::addActor(Actor* actor) {
    mActors.push_back(actor);
}

std::list<Actor*> Scene::getActors() {
    return mActors;
}

