#pragma once
#include "../../test/tester.hpp"
#include "Invader.hpp"
#include "ActorFactory.hpp"
#include "IdentifierProvider.hpp"

struct ActorFactoryEmptyFixture {};

class MockIdentifierProvider: public IdentifierProvider {
 public:
    long getUID() { return 0; }
};

TEST_CASE(ActorFactoryEmptyFixture, checkSpaceInvaderActor) {
    IdentifierProvider *mock = new MockIdentifierProvider();
    ActorFactory *factory = new ActorFactory(mock);
    Invader* invader = factory->createInvader();
    CHECK_EQUAL(invader->getLife(), 10);
};
