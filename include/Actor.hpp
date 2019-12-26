#pragma once

#include <string>
#include <map>
#include "Component.hpp"

class Actor {
 private:
    long mId;
    std::map<std::string, Component*> mComponents;

 public:
    Actor(long id);
    void addComponent(Component *newComponent);
    Component* getComponent(std::string componentName);
    ~Actor();
};

