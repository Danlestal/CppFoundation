#pragma once
#include "raylib.h"
#include "raygui.h"
#include "../Vector2d.hpp"
#include "../events/IEventData.hpp"
#include "../events/EventManager.hpp"
#include "../Actor.hpp"



class EditorRenderingSystem {
 private:
    EventManager* mEventManager;
    Actor* mCamera;
    Vector2 mOffset;

    Vector2D getCameraIngamePosition();
 public:
    EditorRenderingSystem(EventManager* eventManager, Actor* camera, Vector2 cameraOffset);
    ~EditorRenderingSystem();
    void draw();
    void mouseClickReceived(IEventData* pEventData);
};
