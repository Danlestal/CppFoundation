#include "RenderSystem.hpp"
#include <list>
#include "../components/graphics/GraphicComponent.hpp"
#include "../components/BidimensionalComponent.hpp"


RenderSystem::RenderSystem(Scene* scene) {
    mScene = scene;
}

void RenderSystem::draw() {
    std::list<Actor*> actors = mScene->getActors();
    for (auto it = actors.begin(); it != actors.end(); ++it) {
        Actor* actor = (*it);
        if (actor->hasComponent("BidimensionalComponent") && actor->hasComponent("GraphicComponent")) {
            BidimensionalComponent* positionComponent = reinterpret_cast<BidimensionalComponent*>
            (actor->getComponent("BidimensionalComponent"));
            GraphicComponent* component = reinterpret_cast<GraphicComponent*> (actor->getComponent("GraphicComponent"));
            Vector2D position = positionComponent->getPos();
            component->draw(position);
        }
    }
}
