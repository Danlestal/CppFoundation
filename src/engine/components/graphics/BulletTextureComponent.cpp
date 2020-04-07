#include "BulletTextureComponent.hpp"

BulletTextureComponent::BulletTextureComponent(long actorId,
                                                    TextureMap* textureMap,
                                                    EventManager* eventManager): GraphicComponent() {
    mTextureMap = textureMap;
    mActorId = actorId;
    mCounter = 0;
    mEventManager = eventManager;
    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                            &BulletTextureComponent::receiveTick),
                                                            "TickEventDataType");
}

BulletTextureComponent::~BulletTextureComponent() {
    mEventManager->removeListener(fastdelegate::MakeDelegate(this,
                                                            &BulletTextureComponent::receiveTick),
                                                            "TickEventDataType");
}

XenonTextureMap::XenonSprite BulletTextureComponent::getFrame() {
    if (mCounter < 33) {
        return XenonTextureMap::BULLET_SMALL;
    }

    if (mCounter < 66) {
        return XenonTextureMap::BULLET_MEDIUM;
    }

    if (mCounter < 100) {
        return XenonTextureMap::BULLET_BIG;
    }
}

void BulletTextureComponent::draw(Vector2D pos) {
    DrawTextureRec(mTextureMap->getTexture(),
                    mTextureMap->getRectangle(getFrame()),
                    {pos.x, pos.y},
                    WHITE);
}

void BulletTextureComponent::receiveTick(IEventData* pEventData) {
    if (mCounter < 66) {
       mCounter++;
    }
}
