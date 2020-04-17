#include "ButtonComponent.hpp"


ButtonComponent::ButtonComponent(Vector2D position, Vector2D dimensions, std::string name, std::string text) {
        mPosition = position;
        mDimensions = dimensions;
        mName = name;
        mText = text;
}

void ButtonComponent::draw(Vector2D offsetVector) {
        if (GuiButton((Rectangle){
                offsetVector.x + mPosition.x,
                offsetVector.y + mPosition.y,
                mDimensions.x,
                mDimensions.y },
        mText.c_str())) {
                TraceLog(LOG_INFO, "holi");
        }
}
