#pragma once
#include "GraphicComponent.hpp"
#include "../../Vector2d.hpp"
#include "../../events/EventManager.hpp"

class ScoreBoardComponent : public GraphicComponent {
 private:
    int mHeight;
    int mWidth;
    int mCurrentScore;
    EventManager* mEventManager;

 public:
    explicit ScoreBoardComponent(EventManager* eventManager);
    ~ScoreBoardComponent(void);
    void draw(Vector2D pos);
    void invaderKilled(IEventData* pEventData);
};
