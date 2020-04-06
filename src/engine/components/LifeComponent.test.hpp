#pragma once
#include "../../../test/tester.hpp"
#include "LifeComponent.hpp"


struct LifeComponentEmptyFixture {};

TEST_CASE(LifeComponentEmptyFixture, checkLifeComponentReducesItsLife) {
    LifeComponent *component = new LifeComponent(12, 10, new EventManager());
    component->reduceLife(2);
    CHECK_EQUAL(component->getLife(), 8);
};


// void mockListener(IEventData* event) {}

// TEST_CASE(LifeComponentEmptyFixture, whenLifeIs0WeSendAnEvent) {
//     EventManager* manager = new EventManager();
//     LifeComponent *component = new LifeComponent(12, 1, manager);
//     manager->addListener(fastdelegate::MakeDelegate(this, &mockListener), "OrderActorToMoveEventDataType");

//     component->reduceLife(1);
//     CHECK_EQUAL(component->getLife(), 0);
//     CHECK_EQUAL(manager->getEventsNumber(), 1);
// };
