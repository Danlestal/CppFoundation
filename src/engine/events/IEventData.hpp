#pragma once

#include <memory>

class IEventData
{
 public:
    typedef std::shared_ptr<IEventData> IEventDataPtr;
    typedef unsigned long EventType;
    virtual ~IEventData(void) {}
    virtual const EventType& VGetEventType(void) const = 0;
    virtual float GetTimeStamp(void) const = 0;
    virtual IEventDataPtr VCopy(void) const = 0;
    virtual const char* GetName(void) const = 0;
};