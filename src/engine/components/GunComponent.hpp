#pragma once
#include <string>
#include "Component.hpp"
#include "../Vector2d.hpp"
#include "../events/EventManager.hpp"
#include "../events/IEventData.hpp"
#include "../events/UpdateActorPositionEventData.hpp"
#include "../events/SpawnBulletEventData.hpp"
#include "../events/OrderActorToShotEventData.hpp"

class GunComponent : public Component {
 private:
    Vector2D mPosition;
    EventManager* mEventManager;
    const int GUN_FREQUENCY = 45;
    int mTicksSinceLastShot;
 public:
    explicit GunComponent(long mActorId, Vector2D initialPosition, EventManager* evtManager);
    ~GunComponent();
    std::string getType();
    void updatePosition(IEventData* pEventData);
    void receiveShotOrder(IEventData* pEventData);
    void receiveTick(IEventData* pEventData);
};
