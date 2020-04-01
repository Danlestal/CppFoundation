#include "Actor.hpp"

Actor::Actor(long id) {
    mId = id;
}

Actor::~Actor(void) {
    for (std::map<std::string, Component*>::iterator it=mComponents.begin(); it != mComponents.end(); ++it) {
        delete it->second;
    }
}

long Actor::getId() {
    return mId;
}



void Actor::addComponent(Component *newComponent) {
    mComponents[newComponent->getType()] = newComponent;
}

bool Actor::hasComponent(std::string componentName) {
    return (mComponents.count(componentName) == 1);
}

Component* Actor::getComponent(std::string componentType) {
    return mComponents[componentType];
}

