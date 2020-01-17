#pragma once
#include <list>
#include "../Vector2d.hpp"
#include "../Scene.hpp"

struct AABB {
    Vector2D min;
    Vector2D max;
};

struct ActorPhysics{
    Actor* actor;
    AABB box;
};

class PhysicsSystem {
 private:
    std::list<ActorPhysics> mAxisList;
    void broadPhase(Scene* scene);

    // Broad Phase
	void updateAABBList();
	void generateOverlapList();


 public:
    bool collides(AABB firstBox, AABB secondBox);
    void update(Scene* scene);
};
