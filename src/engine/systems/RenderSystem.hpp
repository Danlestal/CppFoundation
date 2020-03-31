#pragma once
#include "../Scene.hpp"
class RenderSystem {
 private:
    Scene* mScene;
 public:
    explicit RenderSystem(Scene* scene);
    void addActor(Actor* newActor);
    void draw();
};
