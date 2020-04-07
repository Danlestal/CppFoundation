#include "SpaceshipTextureComponent.hpp"

SpaceshipTextureComponent::SpaceshipTextureComponent(long actorId,
                                                    TextureMap* textureMap,
                                                    EventManager* eventManager): GraphicComponent() {
    mTextureMap = textureMap;
    mActorId = actorId;
    mVerticalIndex = 0;
    mHorizontalIndex = 0;
    mEventManager = eventManager;
    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                            &SpaceshipTextureComponent::receiveTick),
                                                            "TickEventDataType");
    mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                                            &SpaceshipTextureComponent::receiveOrder),
                                                            "OrderActorToMoveEventDataType");
}

SpaceshipTextureComponent::~SpaceshipTextureComponent() {
    mEventManager->removeListener(fastdelegate::MakeDelegate(this,
                                                            &SpaceshipTextureComponent::receiveTick),
                                                            "TickEventDataType");
    mEventManager->removeListener(fastdelegate::MakeDelegate(this,
                                                            &SpaceshipTextureComponent::receiveOrder),
                                                            "OrderActorToMoveEventDataType");
}

XenonTextureMap::XenonSprite SpaceshipTextureComponent::getFrame() {
    if (mHorizontalIndex < -7) {
        return XenonTextureMap::SPACESHIP_EXTREME_LEFT;
    }

    if (mHorizontalIndex < 0) {
        return XenonTextureMap::SPACESHIP_LEFT;
    }

    if (mHorizontalIndex == 0) {
        return XenonTextureMap::SPACESHIP;
    }

    if (mHorizontalIndex < 7) {
        return XenonTextureMap::SPACESHIP_RIGHT;
    }

    if (mHorizontalIndex >= 7) {
        return XenonTextureMap::SPACESHIP_EXTREME_RIGHT;
    }
}

void SpaceshipTextureComponent::draw(Vector2D pos) {
    DrawTextureRec(mTextureMap->getTexture(),
                    mTextureMap->getRectangle(getFrame()),
                    {pos.x, pos.y},
                    WHITE);
}

void SpaceshipTextureComponent::receiveTick(IEventData* pEventData) {
    if (mVerticalIndex > 0) {
        mVerticalIndex--;
    }

    if (mVerticalIndex < 0) {
        mVerticalIndex++;
    }

    if (mHorizontalIndex > 0) {
        mHorizontalIndex--;
    }

    if (mHorizontalIndex < 0) {
        mHorizontalIndex++;
    }
}

void SpaceshipTextureComponent::receiveOrder(IEventData* pEventData) {
    OrderActorToMoveEventData* moveEvent = reinterpret_cast<OrderActorToMoveEventData*>(pEventData);
    if (moveEvent->getActorId() == mActorId) {
        Vector2D newVector = moveEvent->getDelta();

        mVerticalIndex += (newVector.y * 2);
        if (mVerticalIndex > 10) {
            mVerticalIndex = 10;
        }
        if (mVerticalIndex < -10) {
            mVerticalIndex = -10;
        }

        mHorizontalIndex += (newVector.x * 2);
        if (mHorizontalIndex > 10) {
            mHorizontalIndex = 10;
        }

        if (mHorizontalIndex < -10) {
            mHorizontalIndex = -10;
        }
    }
}
