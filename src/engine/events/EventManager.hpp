#pragma once
#include <list>
#include <map>
#include "BaseEventManager.hpp"

const unsigned int EVENTMANAGER_NUM_QUEUES = 2;

class EventManager : public BaseEventManager {
    typedef std::list<EventListenerDelegate> EventListenerList;
    typedef std::map<IEventData::EventType, EventListenerList> EventListenerMap;
    typedef std::list<IEventData::IEventDataPtr> EventQueue;

    EventListenerMap mEventListeners;
    EventQueue mQueues[EVENTMANAGER_NUM_QUEUES];
    int mActiveQueue;

 public:
    EventManager();
    virtual ~EventManager(void);
    virtual bool addListener(const EventListenerDelegate& eventDelegate, const IEventData::EventType& type);
    virtual bool removeListener(const EventListenerDelegate& eventDelegate, const IEventData::EventType& type);
    virtual bool triggerEvent(const IEventData::IEventDataPtr& pEvent) const;
    virtual bool queueEvent(const IEventData::IEventDataPtr& pEvent);
};
