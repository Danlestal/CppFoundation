#include "GraphicComponent.hpp"
#include "../events/MovePlayerEventData.hpp"

GraphicComponent::GraphicComponent(EventManager* eventManager) {}

std::string GraphicComponent::getType() {
    return "GraphicComponent";
}
