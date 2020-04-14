#pragma once
#include <string>
#include "../../Vector2d.hpp"
#include "../../events/EventManager.hpp"
#include "../../events/OrderActorToMoveEventData.hpp"
#include "BehaviourComponent.hpp"

class VerticalCameraComponent :  public BehaviourComponent {
 private:
  Vector2D mSpeedVector;
  EventManager* mEventManager;
 public:
     explicit VerticalCameraComponent(long actorId, EventManager* eventManager);
    ~VerticalCameraComponent(void);

    virtual void update(Vector2D position);
};
