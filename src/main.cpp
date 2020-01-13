#include <iostream>
#include "raylib.h"


#include "./engine/events/EventManager.hpp"
#include "./engine/IdentifierProvider.hpp"
#include "./engine/RandomIdProvider.hpp"
#include "./engine/KeyboardInputManager.hpp"
#include "./engine/Scene.hpp"
#include "./engine/systems/LogicSystem.hpp"
#include "./engine/systems/RenderSystem.hpp"
#include "./game/ActorFactory.hpp"



int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth,
    screenHeight,
    "raylib");

    SetTargetFPS(60);
    EventManager* eventManager = new EventManager();

    // ALL THIS CRAPOLA SHOULD BE PLACED INSIDE THE MECHANISM TO
    // PARSE THE XML FROM THE SCENE
    IdentifierProvider *mock = new RandomIdProvider();
    ActorFactory *factory = new ActorFactory(mock, eventManager);
    Scene* scene = new Scene(eventManager);
    scene->addActor(factory->createInvader());
    Actor* spaceShip = factory->createPlayerSpaceship();
    scene->addActor(spaceShip);
    std::vector<Actor*> boundaries = factory->createBoundaries(400, 600);
    for (auto it = boundaries.begin(); it != boundaries.end(); ++it) {
        Actor* actor = (*it);
        scene->addActor(actor);
    }
    // PARSE THE XML FROM THE SCENE END

    RenderSystem* view = new RenderSystem();
    LogicSystem* logic = new LogicSystem();

    KeyboardInputManager inputManager = KeyboardInputManager(spaceShip->getId(),eventManager);

    while (!WindowShouldClose()) {
        inputManager.proccessInput();
        eventManager->update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        view->draw(scene);
        logic->updateLogic(scene);
        DrawText("Congrats Dani!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
