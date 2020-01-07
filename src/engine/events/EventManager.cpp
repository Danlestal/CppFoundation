#include "EventManager.hpp"

bool EventManager::addListener(const EventListenerDelegate& eventDelegate, const IEventData::EventType& type) {
    EventListenerList& eventListenerList = mEventListeners[type];
    for (auto it = eventListenerList.begin(); it != eventListenerList.end(); ++it) {
        if (eventDelegate == (*it)) {
            return false;
        }
    }

    eventListenerList.push_back(eventDelegate);
    return true;
}

bool EventManager::triggerEvent(const IEventData::IEventDataPtr& pEvent) const {
    bool processed = false;

    auto findIt = mEventListeners.find(pEvent->VGetEventType());
    if (findIt != mEventListeners.end()) {
        const EventListenerList& eventListenerList = findIt->second;
        for (EventListenerList::const_iterator it = eventListenerList.begin(); it != eventListenerList.end(); ++it) {
            EventListenerDelegate listener = (*it);
            listener(pEvent);  // call the delegate
            processed = true;
        }
    }
    return processed;
}

bool EventManager::removeListener(const EventListenerDelegate& eventDelegate, const IEventData::EventType& type) {
    bool success = false;
    auto findIt = mEventListeners.find(type);
    if (findIt != mEventListeners.end()) {
        EventListenerList& listeners = findIt->second;
        for (auto it = listeners.begin(); it != listeners.end(); ++it) {
            if (eventDelegate == (*it)) {
                listeners.erase(it);
                success = true;
                break;
            }
        }
    }

    return success;
}

bool EventManager::queueEvent(const IEventData::IEventDataPtr& pEvent) {
    if (!pEvent) {
        return false;
    }

    auto findIt = mEventListeners.find(pEvent->VGetEventType());
    if (findIt != mEventListeners.end()) {
        mQueues[mActiveQueue].push_back(pEvent);
        return true;
    } else {
        return false;
    }
}

bool EventManager::update() {
    // swap active queues and clear the new queue after the swap
    int queueToProcess = mActiveQueue;
    mActiveQueue = (mActiveQueue + 1) % EVENTMANAGER_NUM_QUEUES;
    mQueues[mActiveQueue].clear();

    while (!mQueues[queueToProcess].empty()) {
        IEventData::IEventDataPtr pEvent = mQueues[queueToProcess].front();
        mQueues[queueToProcess].pop_front();
        const IEventData::EventType& eventType = pEvent->VGetEventType();
        auto findIt = mEventListeners.find(eventType);
        if (findIt != mEventListeners.end()) {
            const EventListenerList& eventListeners = findIt->second;

            for (auto it = eventListeners.begin(); it != eventListeners.end(); ++it) {
                EventListenerDelegate listener = (*it);
                listener(pEvent);
            }
        }

        // check to see if time ran out
        // currMs = GetTickCount();
        // if (maxMillis != IEventManager::kINFINITE && currMs >= maxMs)
        // {
        //     GCC_LOG("EventLoop", "Aborting event processing; time ran out");
        // 	break;
        // }
    }

    bool queueFlushed = (mQueues[queueToProcess].empty());
    if (!queueFlushed) {
        while (!mQueues[queueToProcess].empty()) {
            IEventData::IEventDataPtr pEvent = mQueues[queueToProcess].back();
            mQueues[queueToProcess].pop_back();
            mQueues[mActiveQueue].push_front(pEvent);
        }
    }

    return queueFlushed;
}
