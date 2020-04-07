#pragma once
#include "GraphicComponent.hpp"
#include "../../XenonTextureMap.hpp"
#include "../../Vector2d.hpp"
#include "../../events/OrderActorToMoveEventData.hpp"

class SpaceshipTextureComponent : public GraphicComponent {
 private:
    EventManager* mEventManager;
    TextureMap* mTextureMap;
    int mHorizontalIndex;
    int mVerticalIndex;

    XenonTextureMap::XenonSprite getFrame();

 public:
     explicit SpaceshipTextureComponent(long actorId, TextureMap* textureMap, EventManager* eventManager);
     ~SpaceshipTextureComponent();
     void draw(Vector2D pos);
     void receiveOrder(IEventData* pEventData);
     void receiveTick(IEventData* pEventData);
};
