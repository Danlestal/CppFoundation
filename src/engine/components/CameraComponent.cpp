#include "CameraComponent.hpp"

CameraComponent::CameraComponent(Camera2D* camera,
                                EventManager* evtManager,
                                Vector2D cameraTarget) {
    mCamera = camera;
    mCameraTarget = cameraTarget;
    mEvtManager = evtManager;
    mEvtManager->addListener(fastdelegate::MakeDelegate(this,
                                                        &CameraComponent::updateCameraTarget),
                                                        "OrderActorToShotEventDataType");
}

CameraComponent::~CameraComponent() {
    mEvtManager->removeListener(fastdelegate::MakeDelegate(this,
                                                            &CameraComponent::updateCameraTarget),
                                                            "TickEventDataType");
}


void CameraComponent::updateCameraTarget(IEventData* pEventData) {
    UpdateActorPositionEventData* moveEvent = reinterpret_cast<UpdateActorPositionEventData*>(pEventData);
    if (moveEvent->getActorId() == mActorId) {
        mCameraTarget += moveEvent->getDelta();
    }
}


std::string CameraComponent::getType() {
    return "CameraComponent";
}
