#pragma once
#include <map>
#include "Event.hpp"
#include "TypeInfo.hpp"
#include "HandlerFunctionBase.hpp"

class EventHandler {
 public:
    void handleEvent(const Event*);
    template< class T, class EventT > void registerEventFunc(T*, void (T::*memFn)(EventT*));
 private:
    typedef std::map< TypeInfo, HandlerFunctionBase* > Handlers;
    Handlers mHandlers;
};


