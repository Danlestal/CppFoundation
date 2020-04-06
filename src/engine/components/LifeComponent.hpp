#pragma once

#include <string>
#include "Component.hpp"
#include "../events/EventManager.hpp"
#include "../events/DestroyActorEventData.hpp"
#include "../events/ActorCollidesEventData.hpp"


class LifeComponent : public Component {
 private:
    int mLife;
    EventManager* mEventManager;
 public:
     LifeComponent(long actorId, int initialLife, EventManager* eventManager);
    ~LifeComponent(void);
    int reduceLife(int lifeDecrement);
    int getLife();
    std::string getType();
    void collisionDetected(IEventData* collisionDetected);
};

