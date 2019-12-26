#pragma once
#include "../../../test/tester.hpp"
#include "LifeComponent.hpp"


struct LifeComponentEmptyFixture {};

TEST_CASE(LifeComponentEmptyFixture, checkLifeComponentIsAlive) {
    LifeComponent *component = new LifeComponent(10);
    CHECK_EQUAL(component->isAlive(), true);
    CHECK_EQUAL(component->getType(), "LifeComponent");
};
