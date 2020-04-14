#include "Actor.hpp"

Actor::Actor(long id) {
    mId = id;
}

Actor::~Actor(void) {
    for (std::map<std::string, std::vector<Component*>>::iterator componenTypesIterator=mComponents.begin();
    componenTypesIterator != mComponents.end();
    ++componenTypesIterator) {
        std::vector<Component*> componentsSameKind = componenTypesIterator->second;
        for (std::vector<Component*>::iterator it= componentsSameKind.begin(); it != componentsSameKind.end(); ++it) {
            delete *it;
        }
        }
    }


long Actor::getId() {
    return mId;
}



void Actor::addComponent(Component *newComponent) {
    // TODO(dvromero): Add a check to ensure that our components can only have one BidimenionalType
    // if I do that I am gonna couple actor with the Bidimensional Component.
    mComponents[newComponent->getType()].push_back(newComponent);
}

bool Actor::hasComponent(std::string componentName) {
    return (mComponents.count(componentName) == 1);
}

std::vector<Component*> Actor::getComponents(std::string componentType) {
    return mComponents[componentType];
}

