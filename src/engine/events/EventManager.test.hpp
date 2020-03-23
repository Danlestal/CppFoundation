#pragma once
#include "../../../test/tester.hpp"
#include "EventManager.hpp"


struct EventManagerEmptyFixture {};

TEST_CASE(EventManagerEmptyFixture, checkDoNoCollides) {
    EventManager* manager = new EventManager();
   
};

