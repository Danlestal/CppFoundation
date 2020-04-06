#pragma once
#include <string>
#include <numeric>
#include "BehaviourComponent.hpp"
#include "../../Vector2d.hpp"
#include "../../events/EventManager.hpp"
#include "../../events/OrderActorToMoveEventData.hpp"
#include "../../events/ActorCollidesEventData.hpp"
#include "../../events/DestroyActorEventData.hpp"
#include "../../events/InvaderKilledEventData.hpp"

class InvaderBehaviourComponent : public BehaviourComponent {
 private:
    Vector2D mSpeedVector;
    EventManager* mEventManager;
 public:
     InvaderBehaviourComponent(long actorId, EventManager* eventManager);
    ~InvaderBehaviourComponent(void);
    void update(Vector2D position);
    void receiveCollision(IEventData* pEventData);
};
