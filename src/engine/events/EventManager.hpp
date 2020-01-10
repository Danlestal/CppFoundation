#pragma once
#include <list>
#include <map>
#include <string>


#include "../3rdParty/FastDelegate/FastDelegate.h"
#include "IEventData.hpp"
const unsigned int EVENTMANAGER_NUM_QUEUES = 2;



class EventManager {
    typedef fastdelegate::FastDelegate1<IEventData*> EventListenerDelegate;
    typedef std::list<EventListenerDelegate> EventListenerList;
    typedef std::map<std::string, EventListenerList> EventListenerMap;
    typedef std::list<IEventData*> EventQueue;

    EventListenerMap mEventListeners;
    EventQueue mQueues[EVENTMANAGER_NUM_QUEUES];
    int mActiveQueue;

 public:
    EventManager() {
        mActiveQueue = 0;
    }
    ~EventManager(void) {}
    virtual bool addListener(const EventListenerDelegate& eventDelegate, const std::string type);
    virtual bool removeListener(const EventListenerDelegate& eventDelegate, const std::string type);
    virtual bool triggerEvent(IEventData* pEvent) const;
    virtual bool queueEvent(IEventData* pEvent);
    virtual bool update();
};
