#include "SceneView.hpp"
#include <list>
#include "./components/GraphicComponent.hpp"

void SceneView::draw(Scene* scene) {
    std::list<Actor*> actors = scene->getActors();
    for (auto it = actors.begin(); it != actors.end(); ++it) {
        Actor* actor = (*it);
        GraphicComponent* component = reinterpret_cast<GraphicComponent*> (actor->getComponent("GraphicComponent"));
        component->draw();
    }
}
