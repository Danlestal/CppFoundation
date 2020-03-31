#pragma once
#include <string>
#include "../../Vector2d.hpp"
#include "../../events/EventManager.hpp"
#include "../Component.hpp"
class BehaviourComponent : public Component {
 public:
    // In a bullet hell game the only thing we need to change the behaviour of the AI its is position in the game.
    virtual void update(Vector2D position) = 0;
    const std::string TYPE = "BehaviourComponent";
    std::string getType(){
        return TYPE;
    }
};
