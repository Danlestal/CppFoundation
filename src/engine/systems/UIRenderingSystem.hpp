#pragma once
#include <vector>
#include "raylib.h"
#include "raygui.h"
#include "../uiComponents/UIComponent.hpp"
#include "../Vector2d.hpp"
#include "../events/IEventData.hpp"
#include "../events/EventManager.hpp"
#include "../Actor.hpp"
#include "../Scene.hpp"



class UIRenderingSystem {
 private:
    Scene* mScene;
    EventManager* mEventManager;
    Actor* mCamera;
    Vector2 mOffset;
    Actor* mSelectedActor;
    std::vector<UIComponent*> mUIComponents;

    Vector2D getCameraIngamePosition();
 public:
    UIRenderingSystem(Scene* scene, Actor* camera, Vector2 cameraOffset);
    ~UIRenderingSystem();
    void draw();
    void init();
    void mouseClickReceived(IEventData* pEventData);
    void actorSelected(IEventData* pEventData);
};
