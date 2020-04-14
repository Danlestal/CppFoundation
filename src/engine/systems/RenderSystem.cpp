#include "RenderSystem.hpp"
#include <list>
#include <vector>
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
            (actor->getComponents("BidimensionalComponent")[0]);

            std::vector<Component*> graphicComponents = actor->getComponents("GraphicComponent");
            Vector2D position = positionComponent->getPos();
            for (auto graphicComponentIt = graphicComponents.begin();
                graphicComponentIt != graphicComponents.end();
                ++graphicComponentIt) {
                    GraphicComponent* component = reinterpret_cast<GraphicComponent*> (*graphicComponentIt);
                    component->draw(position);
            }
        }
    }
}
