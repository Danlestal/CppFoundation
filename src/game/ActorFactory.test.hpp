#pragma once
#include "../../test/tester.hpp"
#include "ActorFactory.hpp"
#include "IdentifierProvider.hpp"

struct ActorFactoryEmptyFixture {};

class MockIdentifierProvider: public IdentifierProvider {
 public:
    long getUID() {
        return 0;
    }
};

TEST_CASE(ActorFactoryEmptyFixture, checkSpaceInvaderActor) {
    IdentifierProvider *mock = new MockIdentifierProvider();
    ActorFactory *factory = new ActorFactory(mock);
    Actor* actor = factory->createInvader();

    CHECK_EQUAL(false, true);
};