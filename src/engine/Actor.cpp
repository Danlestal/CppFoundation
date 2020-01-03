#include "Actor.hpp"

Actor::Actor(long id) {
    mId = id;
}

Actor::~Actor() {}

void Actor::addComponent(Component *newComponent) {
    // TODO(danlestal): Throw a proper exception if
    // the component does not exists
    mComponents[newComponent->getType()] = newComponent;
}

Component* Actor::getComponent(std::string componentType) {
    // TODO(danlestal): Throw a proper exception if
    // the component does not exists
    return mComponents[componentType];
}

