#include "DebugProbe.hpp"


DebugProbe::DebugProbe(Actor* mainActor){
    mMainActor = mainActor;
    mMainActorPosition = reinterpret_cast<BidimensionalComponent*>(mainActor->getComponent("BidimensionalComponent"));
}

void DebugProbe::display() {
    char posX[6];
    sprintf(posX, "%f", mMainActorPosition->getPos().x);
    DrawText(posX, 410, 50, 20, LIGHTGRAY);
    char posY[6];
    sprintf(posY, "%f", mMainActorPosition->getPos().y);
    DrawText(posY, 410, 100, 20, LIGHTGRAY);
}
