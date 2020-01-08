#pragma once
#include <string>
#include "raylib.h"
#include "../3rdParty/FastDelegate/FastDelegate.h"
#include "../events/EventManager.hpp"
#include "Component.hpp"

class GraphicComponent : public Component {
 private:
    int mPosX;
    int mPosY;
 public:
    explicit GraphicComponent(EventManager* eventManager);
    void updatePosition(IEventData* pEventData);
    void draw();
    std::string getType();
};
