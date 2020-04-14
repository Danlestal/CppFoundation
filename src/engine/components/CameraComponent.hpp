#pragma once
#include <string>
#include "raylib.h"
#include "Component.hpp"
#include "../events/OrderActorToMoveEventData.hpp"
#include "../events/UpdateActorPositionEventData.hpp"
#include "../events/ActorCollidesEventData.hpp"
#include "../events/EventManager.hpp"
#include "../Vector2d.hpp"

class CameraComponent : public Component {
 private:
    EventManager* mEvtManager;
    Camera2D* mCamera;
    Vector2D mCameraTarget;

 public:
    CameraComponent(long actorId, Camera2D* camera, EventManager* evtManager, Vector2D cameraTarget);
    ~CameraComponent();


    void updateCameraTarget(IEventData* pEventData);
    std::string getType();
};
