#include "ButtonComponent.hpp"


ButtonComponent::ButtonComponent(
                                Vector2D dimensions,
                                std::string name,
                                std::string text) {
        mDimensions = dimensions;
        mName = name;
        mText = text;
}

void ButtonComponent::draw(Vector2D pos) {
        GuiButton((Rectangle){ pos.x, pos.y, mDimensions.x, mDimensions.y },
        mText.c_str());
}
