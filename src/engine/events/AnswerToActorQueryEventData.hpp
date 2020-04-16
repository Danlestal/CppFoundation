#pragma once
#include <vector>
#include <string>
#include "BaseEventData.hpp"
#include "../Vector2d.hpp"

class AnswerToActorQueryEventData : public BaseEventData {
 private:
  std::vector<long> mActorsThatCollide;

 public:
    explicit AnswerToActorQueryEventData(std::vector<long> actorsThatCollide) {
        mActorsThatCollide = actorsThatCollide;
    }

    std::vector<long> getAnswer() {
        return mActorsThatCollide;
    }

    std::string getEventType(void) const {
        return "AnswerToActorQueryEventDataType";
    }
};
