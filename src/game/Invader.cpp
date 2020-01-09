#include "Invader.hpp"
#include "../engine/components/LifeComponent.hpp"
#include "../engine/components/GraphicComponent.hpp"
#include "../engine/components/GraphicComponentWithTexture.hpp"



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
    GraphicComponentWithTexture* graphicComponent = reinterpret_cast<GraphicComponentWithTexture*>(component);
    return graphicComponent->draw();
}
