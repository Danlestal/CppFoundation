#pragma once
#include "GraphicComponent.hpp"
#include "../XenonTextureMap.hpp"
#include "../Vector2d.hpp"
#include "../events/OrderActorToMoveEventData.hpp"

class TextureComponent : public GraphicComponent {
 private:
    XenonTextureMap mTextureMap;
    int mHorizontalIndex;
    int mVerticalIndex;

    XenonTextureMap::XenonSprite getFrame();

 public:
     explicit TextureComponent(long actorId, XenonTextureMap textureMap);
     void draw(Vector2D pos);
     void receiveOrder(IEventData* pEventData);
     void receiveTick(IEventData* pEventData);
};
