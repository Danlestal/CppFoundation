#include "EditorRenderingSystem.hpp"
#include "../components/BidimensionalComponent.hpp"

EditorRenderingSystem::EditorRenderingSystem(Actor* camera, Vector2 cameraOffset) {
    mCamera = camera;
    mOffset = cameraOffset;
}



void EditorRenderingSystem::draw() {
    BidimensionalComponent* cameraPositionComponent =
    reinterpret_cast<BidimensionalComponent*>(mCamera->getComponents("BidimensionalComponent")[0]);
    Vector2D renderWindowOrigin = cameraPositionComponent->getPos() - Vector2D(mOffset.x, mOffset.y);

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

    GuiButton((Rectangle){ renderWindowOrigin.x + 900, 30, 115, 30 }, "Add boundary");
}