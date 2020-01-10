#pragma once
#include <string>
#include "../events/EventManager.hpp"
#include "Component.hpp"
class BehaviourComponent : public Component {
 private:
    int mHorizontalDirection;
    long mActorId;
    int mSpeed;
    EventManager* mEventManager;
 public:
    explicit BehaviourComponent(long actorId, EventManager* eventManager);
    const std::string TYPE = "BehaviourComponent";
    void update(int posX, int posY);
    std::string getType(){
        return TYPE;
    }
};
