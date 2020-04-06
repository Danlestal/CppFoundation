#include "BoundingSquareComponent.hpp"

BoundingSquareComponent::BoundingSquareComponent(Vector2D dimensions, bool boundary) {
    mBoundary = boundary;
    mDimensions = dimensions;
}

BoundingSquareComponent::BoundingSquareComponent(Vector2D dimensions) {
    mBoundary = false;
    mDimensions = dimensions;
}

BoundingSquareComponent::~BoundingSquareComponent() {}

Vector2D BoundingSquareComponent::getDimensions() {
    return mDimensions;
}

std::string BoundingSquareComponent::getType() {
        return "BoundingSquareComponent";
}

bool BoundingSquareComponent::isBoundary() {
    return mBoundary;
}

