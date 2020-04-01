#include "BidimensionalComponent.hpp"


BidimensionalComponent::BidimensionalComponent(long actorId, Vector2D position, EventManager* evtManager) {
    mPosition = position;
    mActorId = actorId;
    mForbiddenDirection = Vector2D();
    mEvtManager = evtManager;
    mEvtManager->addListener(fastdelegate::MakeDelegate(this, &BidimensionalComponent::updatePosition),
                                                    "OrderActorToMoveEventDataType");
    mEvtManager->addListener(fastdelegate::MakeDelegate(this,
                                                            &BidimensionalComponent::receiveCollision),
                                                            "ActorCollidesEventDataType");
}


BidimensionalComponent::~BidimensionalComponent() {
    mEvtManager->removeListener(fastdelegate::MakeDelegate(
        this,
        &BidimensionalComponent::updatePosition), "OrderActorToMoveEventDataType");

    mEvtManager->removeListener(fastdelegate::MakeDelegate(this,
                                                            &BidimensionalComponent::receiveCollision),
                                                            "ActorCollidesEventDataType");
}

void BidimensionalComponent::updatePosition(IEventData* pEventData) {
    OrderActorToMoveEventData* moveEvent = reinterpret_cast<OrderActorToMoveEventData*>(pEventData);
    if (moveEvent->getActorId() == mActorId) {
        Vector2D realDelta = moveEvent->getDelta() - mForbiddenDirection;
        if (realDelta.x != 0 || realDelta.y != 0) {
            mPosition += realDelta;
            mForbiddenDirection = Vector2D();
            mEvtManager->queueEvent(new UpdateActorPositionEventData(mActorId, realDelta));
        }
    }
}

void BidimensionalComponent::receiveCollision(IEventData* pEventData) {
    ActorCollidesEventData* collisionEvent = reinterpret_cast<ActorCollidesEventData*>(pEventData);
    if ((collisionEvent->getActorId() == mActorId) || (collisionEvent->getCollidesWithId() == mActorId)) {
        mForbiddenDirection = collisionEvent->getCollisionVector();
    }
}


Vector2D BidimensionalComponent::getPos() {
    return mPosition;
}

void BidimensionalComponent::setPos(Vector2D position) {
    mPosition = position;
}

std::string BidimensionalComponent::getType() {
    return "BidimensionalComponent";
}

