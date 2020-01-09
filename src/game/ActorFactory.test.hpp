#pragma once
#include "../../test/tester.hpp"
#include "Invader.hpp"
#include "ActorFactory.hpp"
#include "../engine/IdentifierProvider.hpp"

struct ActorFactoryEmptyFixture {};

class MockIdentifierProvider: public IdentifierProvider {
 public:
    long getUID() { return 0; }
};

TEST_CASE(ActorFactoryEmptyFixture, checkSpaceInvaderActor) {
    IdentifierProvider *mock = new MockIdentifierProvider();
    EventManager* evtManager = new EventManager();
    ActorFactory *factory = new ActorFactory(mock, evtManager);
    Invader* invader = factory->createInvader();
    CHECK_EQUAL(invader->getLife(), 10);
};
