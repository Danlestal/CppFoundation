#include "BaseEventManager.hpp"

static BaseEventManager* gEventMgr = NULL;

BaseEventManager* BaseEventManager::Get(void) {
    return gEventMgr;
}

BaseEventManager::BaseEventManager() {
    if (gEventMgr) {
        delete gEventMgr;
    }
    gEventMgr = this;
}

BaseEventManager::~BaseEventManager(void) {
    if (gEventMgr == this)
        gEventMgr = NULL;
}
