#pragma once

#include "IEventData.hpp"

class BaseEventData : public IEventData {
    const float m_timeStamp;

 public:
    explicit BaseEventData(const float timeStamp = 0.0f) : m_timeStamp(timeStamp) { }
    virtual const EventType& VGetEventType(void) const = 0;
    float GetTimeStamp(void) const { return m_timeStamp; }
};
