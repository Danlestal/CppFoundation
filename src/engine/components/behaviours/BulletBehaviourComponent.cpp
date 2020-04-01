#include "BulletBehaviourComponent.hpp"
#include "../../events/OrderActorToMoveEventData.hpp"

BulletBehaviourComponent::BulletBehaviourComponent(long actorId, EventManager* evtManager) {
    mEventManager = evtManager;
    mSpeedVector = Vector2D(0, -2);
    mActorId = actorId;
    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                    &BulletBehaviourComponent::receiveCollision),
                                                    "ActorCollidesEventDataType");
}

BulletBehaviourComponent::~BulletBehaviourComponent(void) {
    mEventManager->removeListener(fastdelegate::MakeDelegate(this,
                                                &BulletBehaviourComponent::receiveCollision),
                                                "ActorCollidesEventDataType");
}

void BulletBehaviourComponent::update(Vector2D currentPosition ) {
    mEventManager->queueEvent(new OrderActorToMoveEventData(mActorId, mSpeedVector));
}


void BulletBehaviourComponent::receiveCollision(IEventData* pEventData) {
    ActorCollidesEventData* collisionEvent = reinterpret_cast<ActorCollidesEventData*>(pEventData);
    if ((collisionEvent->getActorId() == mActorId) || (collisionEvent->getCollidesWithId() == mActorId)) {
        // DESTROY THE BULLET
        mEventManager->queueEvent(new DestroyActorEventData(mActorId));
    }
}
