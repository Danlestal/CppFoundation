#include "UIRenderingSystem.hpp"
#include "../components/BidimensionalComponent.hpp"
#include "../events/MouseClickEventData.hpp"
#include "../events/ActorQueryEventData.hpp"
#include "../events/AnswerToActorQueryEventData.hpp"
#include "../uiComponents/ButtonComponent.hpp"


UIRenderingSystem::UIRenderingSystem(Scene* scene, Actor* camera, Vector2 cameraOffset) {
    mScene = scene;
    mCamera = camera;
    mOffset = cameraOffset;
    mEventManager = scene->getEventManager();
    mSelectedActor = nullptr;
    mEventManager->addListener(fastdelegate::MakeDelegate(
                                this,
                                &UIRenderingSystem::mouseClickReceived),
                                "MouseClickEventDataType");

    mEventManager->addListener(fastdelegate::MakeDelegate(
                            this,
                            &UIRenderingSystem::actorSelected),
                            "AnswerToActorQueryEventDataType");

}

UIRenderingSystem::~UIRenderingSystem() {
    mEventManager->removeListener(fastdelegate::MakeDelegate(
                                this,
                                &UIRenderingSystem::mouseClickReceived),
                                "MouseClickEventDataType");
}

Vector2D UIRenderingSystem::getCameraIngamePosition() {
    BidimensionalComponent* cameraPositionComponent =
    reinterpret_cast<BidimensionalComponent*>(mCamera->getComponents("BidimensionalComponent")[0]);
    return cameraPositionComponent->getPos();
}

void UIRenderingSystem::mouseClickReceived(IEventData* pEventData) {
    MouseClickEventData* mouseEvent = reinterpret_cast<MouseClickEventData*>(pEventData);
    if (mouseEvent->getMouseButton() == 0) {
        // Try to select an in-game actor
        Vector2 mousePosition = GetMousePosition();
        Vector2D vectorMousePosition = Vector2D(mousePosition.x, mousePosition.y);
        Vector2D result = vectorMousePosition + getCameraIngamePosition();
        result.x -= mOffset.x;
        result.y -= mOffset.y;
        mEventManager->queueEvent(new ActorQueryEventData(result));
    }

    if (mouseEvent->getMouseButton() == 1) {
        // Context Menu?
    }
}

void UIRenderingSystem::actorSelected(IEventData* pEventData) {
    AnswerToActorQueryEventData* mouseEvent = reinterpret_cast<AnswerToActorQueryEventData*>(pEventData);
    std::vector<long> actorIds = mouseEvent->getAnswer();
    if (actorIds.size() > 0) {
        mSelectedActor = mScene->getActor(actorIds[0]);
    }
}

void UIRenderingSystem::draw() {
    Vector2D cameraGamePosition = getCameraIngamePosition();

    Vector2D renderWindowOrigin = cameraGamePosition - Vector2D(mOffset.x, mOffset.y);

    Vector2 mousePosition = GetMousePosition();
    DrawText("Editor Enabled",
                renderWindowOrigin.x + 10,
                renderWindowOrigin.y + 30,
                10,
                DARKGRAY);

    DrawText(FormatText("Mouse Position: [ %.0f, %.0f ]", mousePosition.x, mousePosition.y),
            renderWindowOrigin.x + 10,
            renderWindowOrigin.y + 40,
            10,
            DARKGRAY);

    DrawText(FormatText("Mouse In Game Position: [ %.0f, %.0f ]",
            mousePosition.x + cameraGamePosition.x - mOffset.x,
            mousePosition.y + cameraGamePosition.y - mOffset.y),
            renderWindowOrigin.x + 10,
            renderWindowOrigin.y + 50,
            10,
            DARKGRAY);

    DrawText(FormatText("Camera In Game Position: [ %.0f, %.0f ]", cameraGamePosition.x, cameraGamePosition.y),
            renderWindowOrigin.x + 10,
            renderWindowOrigin.y + 60,
            10,
            DARKGRAY);

    if (GuiButton((Rectangle){ renderWindowOrigin.x + 900, renderWindowOrigin.y + 30, 115, 30 }, "LOAD")) {
        TraceLog(LOG_INFO, "Loading");
    }

    if (GuiButton((Rectangle){ renderWindowOrigin.x + 900, renderWindowOrigin.y + 70, 115, 30 }, "SAVE")) {
        TraceLog(LOG_INFO, "Saving");
    }


    if (mSelectedActor) {
        GuiToggleGroup({  renderWindowOrigin.x + 10,
                                    renderWindowOrigin.y + 110,
                                    300,
                                    100}, "", true);

        DrawText(FormatText("Id: [ %ld ]", mSelectedActor->getId()),
                    renderWindowOrigin.x + 15,
                    renderWindowOrigin.y + 120,
                    10,
                    BLACK);
    }
}

void UIRenderingSystem::init() {
}
