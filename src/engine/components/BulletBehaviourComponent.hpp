#pragma once
#include <string>
#include "../Vector2d.hpp"
#include "../events/EventManager.hpp"
#include "Component.hpp"
#include "../events/ActorCollidesEventData.hpp"
#include "../events/DestroyActorEventData.hpp"


class BulletBehaviourComponent : public Component {
 private:
    Vector2D mSpeedVector;
    EventManager* mEventManager;
 public:
    explicit BulletBehaviourComponent(long actorId, EventManager* eventManager);
    void update(IEventData* position);
    void receiveCollision(IEventData* pEventData);

    const std::string TYPE = "BulletBehaviourComponent";
    std::string getType(){ return TYPE; }
};
