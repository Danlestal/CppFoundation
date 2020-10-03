#pragma once
#include "GraphicComponent.hpp"
#include "../../XenonTextureMap.hpp"
#include "../../Vector2d.hpp"
#include "../../events/OrderActorToMoveEventData.hpp"

class NonAnimatedTextureComponent : public GraphicComponent {
 public:
     explicit NonAnimatedTextureComponent(long actorId, Vector2D position, Vector2D dimensions);
     ~NonAnimatedTextureComponent();
     void draw(Vector2D pos);
};
