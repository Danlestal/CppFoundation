#include "TextureComponent.hpp"

TextureComponent::TextureComponent(long actorId, XenonTextureMap textureMap): GraphicComponent() {
    mTextureMap = textureMap;
    mActorId = actorId;
}

void TextureComponent::draw(Vector2D pos) {
    DrawTextureRec(mTextureMap.getTexture(),
                    mTextureMap.getRectangle(0),
                    {pos.x, pos.y},
                    WHITE);
}


void TextureComponent::receiveOrder(IEventData* pEventData) {
    OrderActorToMoveEventData* moveEvent = reinterpret_cast<OrderActorToMoveEventData*>(pEventData);
    if (moveEvent->getActorId() == mActorId) {}
}
