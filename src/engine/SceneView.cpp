#include "SceneView.hpp"
#include <list>
#include "./components/GraphicComponent.hpp"
#include "./components/BidimensionalComponent.hpp"

void SceneView::draw(Scene* scene) {
    std::list<Actor*> actors = scene->getActors();
    for (auto it = actors.begin(); it != actors.end(); ++it) {
        Actor* actor = (*it);
        if (actor->hasComponent("BidimensionalComponent") && actor->hasComponent("GraphicComponent")) {
            BidimensionalComponent* positionComponent =reinterpret_cast<BidimensionalComponent*> (actor->getComponent("BidimensionalComponent"));
            GraphicComponent* component = reinterpret_cast<GraphicComponent*> (actor->getComponent("GraphicComponent"));
            component->draw(positionComponent->getPosx(),
                            positionComponent->getPosY());
        }
    }
}
