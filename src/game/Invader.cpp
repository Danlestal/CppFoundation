#include "Invader.hpp"
#include "../engine/components/LifeComponent.hpp"
#include "../engine/components/GraphicComponent.hpp"



Invader::Invader(Actor* actor) {
    mActor = actor;
}

int Invader::getLife() {
    Component* component = mActor->getComponent("LifeComponent");
    LifeComponent* lifeComponent = reinterpret_cast<LifeComponent*>(component);
    return lifeComponent->getLife();
}

void Invader::draw() {
    Component* component = mActor->getComponent("GraphicComponent");
    GraphicComponent* graphicComponent = reinterpret_cast<GraphicComponent*>(component);
    return graphicComponent->draw();
}
