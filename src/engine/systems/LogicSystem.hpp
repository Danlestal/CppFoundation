#pragma once
#include "../Scene.hpp"
class LogicSystem {
 private:
    Scene* mScene;
 public:
    explicit LogicSystem(Scene* scene);
    void updateLogic();
};
