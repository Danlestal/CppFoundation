#include "CameraComponent.hpp"

CameraComponent::CameraComponent(long actorId,
                                Camera2D* camera,
                                EventManager* evtManager,
                                Vector2D cameraTarget) {
    mCamera = camera;
    mCameraTarget = cameraTarget;
    mEvtManager = evtManager;
    mActorId = actorId;
    mEvtManager->addListener(fastdelegate::MakeDelegate(this,
                                                        &CameraComponent::updateCameraTarget),
                                                        "UpdateActorPositionEventDataType");
}

CameraComponent::~CameraComponent() {
    mEvtManager->removeListener(fastdelegate::MakeDelegate(this,
                                                            &CameraComponent::updateCameraTarget),
                                                            "UpdateActorPositionEventDataType");
}


void CameraComponent::updateCameraTarget(IEventData* pEventData) {
    UpdateActorPositionEventData* moveEvent = reinterpret_cast<UpdateActorPositionEventData*>(pEventData);
    if (moveEvent->getActorId() == mActorId) {
        mCameraTarget += moveEvent->getDelta();
        mCamera->target.x = mCameraTarget.x;
        mCamera->target.y = mCameraTarget.y;
    }
}


std::string CameraComponent::getType() {
    return "CameraComponent";
}
