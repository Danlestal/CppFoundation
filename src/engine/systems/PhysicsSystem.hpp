#pragma once
#include <vector>
#include <list>
#include "../events/EventManager.hpp"
#include "../Vector2d.hpp"
#include "../Scene.hpp"

struct AABB {
    Vector2D min;
    Vector2D max;

    AABB operator+=(const Vector2D& delta) {
        min += delta;
        max += delta;
        return *this;
    }
};

struct ActorPhysics{
    long actorId;
    Vector2D lastMovement;
    bool isBoundary;
    AABB box;
};

static bool compareYAxis(const ActorPhysics* first, const ActorPhysics* second) {
    return (first->box.min.y < second->box.min.y);
}

class PhysicsSystem {
 private:
    EventManager* mEventManager;
    Scene* mScene;
    std::vector<ActorPhysics*> mAxisList;

    void createAndAddActorIfNeeded(Actor* actor);
    std::vector<ActorPhysics*> createActorPhysics(Actor* actor);
    ActorPhysics* findActor(long id);
    int findActorIndex(long id);
    void removeActorById(long id);

    void updatePosition(IEventData* pEventData);
    void addActor(IEventData* pEventData);
    void removeActor(IEventData* pEventData);

    void checkActorPhysics(ActorPhysics* toCheck);

 public:
    explicit PhysicsSystem(Scene* scene);
    bool collides(AABB firstBox, AABB secondBox);
};
