#include "BoundingSquareComponent.hpp"

BoundingSquareComponent::BoundingSquareComponent(Vector2D dimensions) {
    mDimensions = dimensions;
}

BoundingSquareComponent::~BoundingSquareComponent() {}

Vector2D BoundingSquareComponent::getDimensions() {
    return mDimensions;
}

std::string BoundingSquareComponent::getType() {
        return "BoundingSquareComponent";
}

