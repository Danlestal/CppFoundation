#pragma once
#include <string>
#include "../../Vector2d.hpp"
#include "../../events/EventManager.hpp"
#include "BehaviourComponent.hpp"

class InvaderBehaviourComponent : public BehaviourComponent {
 private:
    Vector2D mSpeedVector;
    EventManager* mEventManager;
 public:
    explicit InvaderBehaviourComponent(long actorId, EventManager* eventManager);
    void update(Vector2D position);
};
