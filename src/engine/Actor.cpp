#include "Actor.hpp"

Actor::Actor(long id) {
    mId = id;
}

long Actor::getId() {
    return mId;
}

Actor::~Actor() {}

void Actor::addComponent(Component *newComponent) {
    mComponents[newComponent->getType()] = newComponent;
}

bool Actor::hasComponent(std::string componentName) {
    return (mComponents.count(componentName) == 1);
}

Component* Actor::getComponent(std::string componentType) {
    return mComponents[componentType];
}

