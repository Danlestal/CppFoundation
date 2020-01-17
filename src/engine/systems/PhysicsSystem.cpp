#include "PhysicsSystem.hpp"

void PhysicsSystem::update(Scene* scene) {}

void PhysicsSystem::broadPhase(Scene* scene) {
    //1. Add the x to the axis list.
    //2. Get the nodes that overlap.
    //3. Order those on 
}


bool PhysicsSystem::collides(AABB firstBox, AABB secondBox) {
    return (firstBox.min.x < secondBox.max.x &&
        firstBox.max.x > secondBox.min.x &&
        firstBox.min.y < secondBox.max.y &&
        firstBox.max.y > secondBox.min.y);
}
