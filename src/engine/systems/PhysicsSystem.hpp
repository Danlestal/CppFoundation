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
    AABB box;
};

static bool compareYAxis(const ActorPhysics* first, const ActorPhysics* second) {
    return (first->box.min.y < second->box.min.y);
}

class PhysicsSystem {
 private:
    EventManager* mEventManager;
    std::vector<ActorPhysics*> mAxisList;
    void initAxisList(std::list<Actor*> actors);
    ActorPhysics* createActorPhysics(Actor* actor);
    ActorPhysics* findActor(long id);
    void updatePosition(IEventData* pEventData);

 public:
    explicit PhysicsSystem(EventManager* eventManager);
    void init(Scene* scene);
    bool collides(AABB firstBox, AABB secondBox);
    void checkActorPhysics(ActorPhysics* toCheck);
};
