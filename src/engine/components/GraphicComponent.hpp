#pragma once
#include <string>
#include "raylib.h"
#include "../Vector2d.hpp"
#include "../3rdParty/FastDelegate/FastDelegate.h"
#include "../events/EventManager.hpp"
#include "Component.hpp"

class GraphicComponent : public Component {
 public:
    explicit GraphicComponent(EventManager* eventManager);
    void updatePosition(IEventData* pEventData);
    virtual void draw(Vector2D) = 0;
    std::string getType();
};
