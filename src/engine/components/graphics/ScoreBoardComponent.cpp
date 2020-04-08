#include "ScoreBoardComponent.hpp"

ScoreBoardComponent::ScoreBoardComponent(EventManager* eventManager): GraphicComponent() {
        mCurrentScore = 0;
        mEventManager = eventManager;
        mEventManager->addListener(fastdelegate::MakeDelegate(this,
                                            &ScoreBoardComponent::invaderKilled),
                                            "InvaderKilledEventDataType");
}


ScoreBoardComponent::~ScoreBoardComponent(void) {
        mEventManager->removeListener(fastdelegate::MakeDelegate(this,
                                        &ScoreBoardComponent::invaderKilled),
                                        "InvaderKilledEventDataType");
}

void ScoreBoardComponent::draw(Vector2D pos) {
    char score[4];
    sprintf(score, "%i", mCurrentScore);
    DrawText(score, pos.x, pos.y, 5, RED);
}


void ScoreBoardComponent::invaderKilled(IEventData* pEventData) {
    mCurrentScore++;
}
