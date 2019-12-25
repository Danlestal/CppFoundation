#pragma once
#include "../../../test/tester.hpp"
#include "LifeComponent.hpp"


struct LifeComponentEmptyFixture {};

TEST_CASE(LifeComponentEmptyFixture, checkLifeComponentIsAlive) {
    engine::LifeComponent *component = new engine::LifeComponent(10);
    CHECK_EQUAL(component->isAlive(), true);
};
