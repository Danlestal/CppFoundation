#pragma once
#include "GraphicComponent.hpp"
#include "../../XenonTextureMap.hpp"
#include "../../Vector2d.hpp"
#include "../../events/OrderActorToMoveEventData.hpp"

class InvaderTextureComponent : public GraphicComponent {
 private:
    EventManager* mEventManager;
    TextureMap* mTextureMap;
    int mHorizontalIndex;
    int mVerticalIndex;

    XenonTextureMap::XenonSprite getFrame();

 public:
     explicit InvaderTextureComponent(long actorId, TextureMap* textureMap, EventManager* eventManager);
     ~InvaderTextureComponent();
     void draw(Vector2D pos);
     void receiveOrder(IEventData* pEventData);
     void receiveTick(IEventData* pEventData);
};
