#include "EventHandler.hpp"
#include "MemberFunctionHandler.hpp"

template < class T, class EventT > void EventHandler::registerEventFunc(T* obj, void (T::*memFn)(EventT*)) {
    mHandlers[TypeInfo(typeid(EventT))]= new MemberFunctionHandler< T, EventT >(obj, memFn);
}

void EventHandler::handleEvent(const Event* event) { 
    Handlers::iterator it = mHandlers.find(TypeInfo(typeid(*event)));
    if (it != mHandlers.end()) {
        it->second->exec(event);
    }
}
