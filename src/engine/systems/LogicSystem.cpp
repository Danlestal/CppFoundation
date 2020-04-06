#include "LogicSystem.hpp"
#include <list>
#include "../components/behaviours/BehaviourComponent.hpp"
#include "../components/BidimensionalComponent.hpp"


LogicSystem::LogicSystem(Scene* scene) {
    mScene = scene;
}

void LogicSystem::updateLogic() {
    std::list<Actor*> actors = mScene->getActors();
    for (auto it = actors.begin(); it != actors.end(); ++it) {
        Actor* actor = (*it);
        if (actor->hasComponent("BidimensionalComponent") && actor->hasComponent("BehaviourComponent")) {
            BidimensionalComponent* positionComponent = reinterpret_cast<BidimensionalComponent*>(
                actor->getComponent("BidimensionalComponent"));
            BehaviourComponent* component = reinterpret_cast<BehaviourComponent*>(
                actor->getComponent("BehaviourComponent"));
            component->update(positionComponent->getPos());
        }
    }
}