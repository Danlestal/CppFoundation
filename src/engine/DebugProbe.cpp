#include "DebugProbe.hpp"


DebugProbe::DebugProbe(Actor* mainActor){
    mMainActor = mainActor;
    mMainActorPosition = reinterpret_cast<BidimensionalComponent*>(mainActor->getComponent("BidimensionalComponent"));
}

void DebugProbe::display() {
    char posX[4];
    sprintf(posX, "%f", mMainActorPosition->getPos().x);
    DrawText(posX, 410, 50, 5, LIGHTGRAY);
    char posY[4];
    sprintf(posY, "%f", mMainActorPosition->getPos().y);
    DrawText(posY, 480, 50, 5, LIGHTGRAY);
}
