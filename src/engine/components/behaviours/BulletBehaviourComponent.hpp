#pragma once
#include <string>
#include "../../Vector2d.hpp"
#include "../../events/EventManager.hpp"
#include "../../events/ActorCollidesEventData.hpp"
#include "../../events/DestroyActorEventData.hpp"
#include "BehaviourComponent.hpp"

class BulletBehaviourComponent : public BehaviourComponent {
 private:
    Vector2D mSpeedVector;
    EventManager* mEventManager;
 public:
    BulletBehaviourComponent(long actorId, EventManager* eventManager);
    ~BulletBehaviourComponent(void);
    void update(Vector2D position);
    void receiveCollision(IEventData* pEventData);
};
