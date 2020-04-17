#pragma once
#include <vector>
#include "raylib.h"
#include "raygui.h"
#include "../uiComponents/UIComponent.hpp"
#include "../Vector2d.hpp"
#include "../events/IEventData.hpp"
#include "../events/EventManager.hpp"
#include "../Actor.hpp"



class UIRenderingSystem {
 private:
    EventManager* mEventManager;
    Actor* mCamera;
    Vector2 mOffset;
    std::vector<UIComponent*> mUIComponents;

    Vector2D getCameraIngamePosition();
 public:
    UIRenderingSystem(EventManager* eventManager, Actor* camera, Vector2 cameraOffset);
    ~UIRenderingSystem();
    void draw();
    void init();
    void mouseClickReceived(IEventData* pEventData);
};
