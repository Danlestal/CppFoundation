#include "GraphicComponent.hpp"
#include "../events/MovePlayerEventData.hpp"

GraphicComponent::GraphicComponent(EventManager* eventManager) {
    mPosX = 0;
    mPosY = 0;
    eventManager->addListener(fastdelegate::MakeDelegate(this,
                                            &GraphicComponent::updatePosition),
                                            "MovePlayerEventDataType");
}


void GraphicComponent::updatePosition(IEventData* pEventData) {
    MovePlayerEventData* moveEvent = reinterpret_cast<MovePlayerEventData*>(pEventData);
    mPosX += moveEvent->getIncrementX();
    mPosY += moveEvent->getIncrementY();
}



std::string GraphicComponent::getType() {
    return "GraphicComponent";
}
