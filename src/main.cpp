#include <iostream>
#include "raylib.h"

#include "IdentifierProvider.hpp"
#include "ActorFactory.hpp"
#include "Invader.hpp"
#include "./engine/events/EventManager.hpp"
#include "./engine/RandomIdProvider.hpp"
#include "./engine/KeyboardInputManager.hpp"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth,
    screenHeight,
    "raylib");

    SetTargetFPS(60);
    EventManager* eventManager = new EventManager();
    IdentifierProvider *mock = new RandomIdProvider();
    ActorFactory *factory = new ActorFactory(mock, eventManager);
    Invader* invader = factory->createInvader();
    KeyboardInputManager inputManager = KeyboardInputManager(eventManager);

    while (!WindowShouldClose()) {
        inputManager.proccessInput();
        eventManager->update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        invader->draw();
        DrawText("Congrats Dani!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
