#include "Invader.hpp"
#include "../engine/components/LifeComponent.hpp"



Invader::Invader(Actor* actor) {
    mActor = actor;
}

int Invader::getLife() {
    Component* component = mActor->getComponent("LifeComponent");
    LifeComponent* lifeComponent = reinterpret_cast<LifeComponent*>(component);
    return lifeComponent->getLife();
}
