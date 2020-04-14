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
                actor->getComponents("BidimensionalComponent")[0]);
            BehaviourComponent* component = reinterpret_cast<BehaviourComponent*>(
                actor->getComponents("BehaviourComponent")[0]);
            component->update(positionComponent->getPos());
        }
    }
}