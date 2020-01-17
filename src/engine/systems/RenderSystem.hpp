#pragma once
#include "../Scene.hpp"
class RenderSystem {
    
 public:
    void addActor(Actor* newActor);
    void draw(Scene* sceneToDraw);
};
