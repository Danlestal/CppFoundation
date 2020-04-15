#include "EditorRenderingSystem.hpp"
#include "../components/BidimensionalComponent.hpp"

EditorRenderingSystem::EditorRenderingSystem(Actor* camera) {
    mCamera = camera;
}



void EditorRenderingSystem::draw() {
    BidimensionalComponent* cameraPositionComponent =
    reinterpret_cast<BidimensionalComponent*>(mCamera->getComponents("BidimensionalComponent")[0]);
    Vector2D cameraPosition = cameraPositionComponent->getPos();

    Vector2 mousePosition = GetMousePosition();
    DrawText("Editor Enabled",
    cameraPosition.x,
    cameraPosition.y,
    10,
    DARKGRAY);

    DrawText(FormatText("Mouse Position: [ %.0f, %.0f ]", mousePosition.x, mousePosition.y),
    cameraPosition.x,
    cameraPosition.y  + 15,
    10,
    DARKGRAY);
}