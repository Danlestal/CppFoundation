#include <iostream>
#include "raylib.h"


#include "./engine/events/EventManager.hpp"
#include "./engine/IdentifierProvider.hpp"
#include "./engine/RandomIdProvider.hpp"
#include "./engine/KeyboardInputManager.hpp"
#include "./engine/Scene.hpp"
#include "./engine/SceneView.hpp"
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
    Actor* invader = factory->createInvader();
    Scene* scene = new Scene(eventManager);
    scene->addActor(invader);
    // PARSE THE XML FROM THE SCENE END

    SceneView* view = new SceneView();

    KeyboardInputManager inputManager = KeyboardInputManager(eventManager);

    while (!WindowShouldClose()) {
        inputManager.proccessInput();
        eventManager->update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        view->draw(scene);
        DrawText("Congrats Dani!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
