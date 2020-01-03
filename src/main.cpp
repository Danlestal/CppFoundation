#include <iostream>
#include "raylib.h"

#include "IdentifierProvider.hpp"
#include "./engine/RandomIdProvider.hpp"
#include "ActorFactory.hpp"
#include "Invader.hpp"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth,
    screenHeight,
    "raylib");

    SetTargetFPS(60);

    IdentifierProvider *mock = new RandomIdProvider();
    ActorFactory *factory = new ActorFactory(mock);
    Invader* invader = factory->createInvader();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        invader->draw();
        DrawText("Congrats Dani!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
