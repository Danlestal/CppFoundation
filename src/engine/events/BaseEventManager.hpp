
#pragma once
#include <memory>
#include "../3rdParty/FastDelegate/FastDelegate.h"

#include "IEventData.hpp"

typedef fastdelegate::FastDelegate1<IEventData::IEventDataPtr> EventListenerDelegate;

class BaseEventManager {
 public:
    BaseEventManager();
    virtual ~BaseEventManager(void);
    virtual bool addListener(const EventListenerDelegate& eventDelegate, const IEventData::EventType& type) = 0;
    static BaseEventManager* Get(void);
};
