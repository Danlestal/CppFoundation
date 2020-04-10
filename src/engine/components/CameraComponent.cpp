#include "CameraComponent.hpp"

CameraComponent::CameraComponent(Camera2D* camera,
                                EventManager* evtManager,
                                Vector2D cameraTarget) {
    mCamera = camera;
    mCameraTarget = cameraTarget;
    mEvtManager = evtManager;
    mEvtManager->addListener(fastdelegate::MakeDelegate(this,
                                                            &CameraComponent::updateCameraTarget),
                                                            "TickEventDataType");
}

CameraComponent::~CameraComponent(){
    mEvtManager->removeListener(fastdelegate::MakeDelegate(this,
                                                            &CameraComponent::updateCameraTarget),
                                                            "TickEventDataType");
}


void CameraComponent::updateCameraTarget(IEventData* pEventData) {
        mCameraTarget += {0, -0.5};
        mCamera->target = {mCameraTarget.x, mCameraTarget.y};
}


std::string CameraComponent::getType(){
    return "CameraComponent";
}