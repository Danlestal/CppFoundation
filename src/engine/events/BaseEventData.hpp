#pragma once
#include <string>
#include "IEventData.hpp"

class BaseEventData : public IEventData {
    const float mTimeStamp;

 public:
    explicit BaseEventData(const float timeStamp = 0.0f) : mTimeStamp(timeStamp) { }
    virtual std::string getEventType(void) const = 0;
    float getTimeStamp(void) const { return mTimeStamp; }
};
