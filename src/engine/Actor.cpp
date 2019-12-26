#include "Actor.hpp"

Actor::Actor(long id) {
    mId = id;
}

Actor::~Actor() {}

void Actor::addComponent(Component *newComponent) {
    mComponents[newComponent->getType()] = newComponent;
}

Component* Actor::getComponent(std::string componentType) {
    return mComponents[componentType];
}

