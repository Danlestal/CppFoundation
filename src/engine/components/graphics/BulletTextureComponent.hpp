#pragma once
#include "GraphicComponent.hpp"
#include "../../XenonTextureMap.hpp"
#include "../../Vector2d.hpp"
#include "../../events/OrderActorToMoveEventData.hpp"

class BulletTextureComponent : public GraphicComponent {
 private:
    EventManager* mEventManager;
    TextureMap* mTextureMap;
    int mCounter;

    XenonTextureMap::XenonSprite getFrame();

 public:
     explicit BulletTextureComponent(long actorId, TextureMap* textureMap, EventManager* eventManager);
     ~BulletTextureComponent();
     void draw(Vector2D pos);
     void receiveTick(IEventData* pEventData);
};
