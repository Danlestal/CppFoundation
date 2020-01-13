#include "LogicSystem.hpp"
#include <list>
#include "./components/BehaviourComponent.hpp"
#include "./components/BidimensionalComponent.hpp"

void LogicSystem::updateLogic(Scene* scene) {
    std::list<Actor*> actors = scene->getActors();
    for (auto it = actors.begin(); it != actors.end(); ++it) {
        Actor* actor = (*it);
        if (actor->hasComponent("BidimensionalComponent") && actor->hasComponent("BehaviourComponent")) {
            BidimensionalComponent* positionComponent = reinterpret_cast<BidimensionalComponent*> (actor->getComponent("BidimensionalComponent"));
            BehaviourComponent* component = reinterpret_cast<BehaviourComponent*> (actor->getComponent("BehaviourComponent"));
            component->update(positionComponent->getPosx(),
                            positionComponent->getPosY());
        }
    }
}
