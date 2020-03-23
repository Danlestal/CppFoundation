#include "EventManager.hpp"


bool EventManager::addListener(const EventListenerDelegate& eventDelegate, const std::string type) {
    EventListenerList& eventListenerList = mEventListeners[type];
    for (auto it = eventListenerList.begin(); it != eventListenerList.end(); ++it) {
        if (eventDelegate == (*it)) {
            return false;
        }
    }

    eventListenerList.push_back(eventDelegate);
    return true;
}

bool EventManager::triggerEvent(IEventData* pEvent) const {
    bool processed = false;
    auto findIt = mEventListeners.find(pEvent->getEventType());
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

bool EventManager::removeListener(const EventListenerDelegate& eventDelegate, const std::string type) {
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


bool EventManager::queueEvent(IEventData* pEvent) {
    if (!pEvent) {
        return false;
    }

    auto findIt = mEventListeners.find(pEvent->getEventType());
    if (findIt != mEventListeners.end()) {
        mQueues[mActiveQueue].push_back(pEvent);
        return true;
    } else {
        return false;
    }
}

bool EventManager::update() {
    int queueToProcess = mActiveQueue;
    mActiveQueue = (mActiveQueue + 1) % EVENTMANAGER_NUM_QUEUES;
    mQueues[mActiveQueue].clear();

    while (!mQueues[queueToProcess].empty()) {
        IEventData* pEvent = mQueues[queueToProcess].front();
        mQueues[queueToProcess].pop_front();
        const std::string eventType = pEvent->getEventType();
        auto findIt = mEventListeners.find(eventType);
        if (findIt != mEventListeners.end()) {
            const EventListenerList& eventListeners = findIt->second;

            for (auto it = eventListeners.begin(); it != eventListeners.end(); ++it) {
                EventListenerDelegate listener = (*it);
                listener(pEvent);
            }
        }
    }

    bool queueFlushed = (mQueues[queueToProcess].empty());
    if (!queueFlushed) {
        while (!mQueues[queueToProcess].empty()) {
            IEventData* pEvent = mQueues[queueToProcess].back();
            mQueues[queueToProcess].pop_back();
            mQueues[mActiveQueue].push_front(pEvent);
        }
    }

    return queueFlushed;
}


int EventManager::getNumberOfEvents(){
    return static_cast<int>(mQueues[mActiveQueue].size());
}