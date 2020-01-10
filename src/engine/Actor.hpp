#pragma once

#include <string>
#include <map>
#include "./components/Component.hpp"

class Actor {
 private:
    long mId;
    std::map<std::string, Component*> mComponents;

 public:
    explicit Actor(long id);
    void addComponent(Component *newComponent);
    bool hasComponent(std::string componentName);
    Component* getComponent(std::string componentName);
    ~Actor();
};

