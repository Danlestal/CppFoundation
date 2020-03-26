#pragma once
#include "GraphicComponent.hpp"
#include "../XenonTextureMap.hpp"
#include "../Vector2d.hpp"
#include "../events/OrderActorToMoveEventData.hpp"

class AnimatedTextureComponent : public GraphicComponent {
 private:
    TextureMap* mTextureMap;
    int mHorizontalIndex;
    int mVerticalIndex;

    XenonTextureMap::XenonSprite getFrame();

 public:
     explicit AnimatedTextureComponent(long actorId, TextureMap* textureMap);
     void draw(Vector2D pos);
     void receiveOrder(IEventData* pEventData);
     void receiveTick(IEventData* pEventData);
};
