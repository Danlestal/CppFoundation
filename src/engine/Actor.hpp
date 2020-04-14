#pragma once

#include <string>
#include <map>
#include <vector>
#include "./components/Component.hpp"

class Actor {
 private:
    long mId;
    std::map<std::string, std::vector<Component*>> mComponents;

 public:
    explicit Actor(long id);
    ~Actor(void);
    long getId();
    void addComponent(Component *newComponent);
    bool hasComponent(std::string componentName);
    std::vector<Component*> getComponents(std::string componentName);
};

