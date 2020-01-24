#pragma once
#include "../../../test/tester.hpp"
#include "PhysicsSystem.hpp"


struct PhysSystemEmptyFixture {};

TEST_CASE(PhysSystemEmptyFixture, checkDoNoCollides) {
    PhysicsSystem *system = new PhysicsSystem(new EventManager());
    AABB redBox = AABB();
    redBox.min = Vector2D(0, 0);
    redBox.max = Vector2D(10, 10);  // Basically a square of 10,10 with its begginning at 0,0

    AABB blueBox = AABB();
    blueBox.min = Vector2D(11, 11);
    blueBox.max = Vector2D(40, 40);  // Basically a square of 10,10 with its begginning at 0,0

    CHECK_EQUAL(system->collides(redBox, blueBox), false);
};


TEST_CASE(PhysSystemEmptyFixture, checkCollides) {
    PhysicsSystem *system = new PhysicsSystem(new EventManager());
    AABB redBox = AABB();
    redBox.min = Vector2D(0, 0);
    redBox.max = Vector2D(10, 10);  // Basically a square of 10,10 with its begginning at 0,0

    AABB blueBox = AABB();
    blueBox.min = Vector2D(9, 9);
    blueBox.max = Vector2D(40, 40);

    AABB greenBox = AABB();
    greenBox.min = Vector2D(-1, -1);
    greenBox.max = Vector2D(40, 40);

    CHECK_EQUAL(system->collides(redBox, blueBox), true);
    CHECK_EQUAL(system->collides(redBox, greenBox), true);
    CHECK_EQUAL(system->collides(greenBox, redBox), true);
};


TEST_CASE(PhysSystemEmptyFixture, checkDoNotCollidesOnBoundary) {
    PhysicsSystem *system = new PhysicsSystem(new EventManager());
    AABB redBox = AABB();
    redBox.min = Vector2D(0, 0);
    redBox.max = Vector2D(10, 10);  // Basically a square of 10,10 with its begginning at 0,0

    AABB blueBox = AABB();
    blueBox.min = Vector2D(10, 10);
    blueBox.max = Vector2D(40, 40);  // Basically a square of 10,10 with its begginning at 0,0

    CHECK_EQUAL(system->collides(redBox, blueBox), false);
};
