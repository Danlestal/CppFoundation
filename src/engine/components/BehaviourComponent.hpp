#pragma once
#include <string>
#include "../Vector2d.hpp"
#include "../events/EventManager.hpp"
#include "Component.hpp"
class BehaviourComponent : public Component {
 private:
    Vector2D mSpeedVector;
    EventManager* mEventManager;
 public:
    explicit BehaviourComponent(long actorId, EventManager* eventManager);
    const std::string TYPE = "BehaviourComponent";
    void update(Vector2D position);
    std::string getType(){
        return TYPE;
    }
};
