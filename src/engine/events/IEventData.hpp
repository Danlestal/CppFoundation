#pragma once

#include <memory>
#include <string>

class IEventData {
 public:
    virtual ~IEventData(void) {}
    virtual std::string getEventType(void) const = 0;
    virtual float getTimeStamp(void) const = 0;
};
