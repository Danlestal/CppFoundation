#define GENERATE_UNIT_TEST_MAIN
#include "tester.hpp"
#include "../src/engine/components/LifeComponent.test.hpp"

struct MyFixture {
    const int CommonData = 10;
};

TEST_CASE(MyFixture, Test1) {
    // MyFixture constructor called
    CHECK_EQUAL(CommonData, 10);
    // MyFixture destructor called
}
TEST_CASE(MyFixture, Test2) {
    // MyFixture constructor called
    CHECK_EQUAL(CommonData, 10);
    // MyFixture destructor called
}
