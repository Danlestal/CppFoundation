/*******************************************************************************************
*
*   raygui - portable window
*
*   DEPENDENCIES:
*       raylib 2.1  - Windowing/input management and drawing.
*       raygui 2.0  - Immediate-mode GUI controls.
*
*   COMPILATION (Windows - MinGW):
*       gcc -o $(NAME_PART).exe $(FILE_NAME) -I../../src -lraylib -lopengl32 -lgdi32 -std=c99
*
*   LICENSE: zlib/libpng
*
*   Copyright (c) 2020 Ramon Santamaria (@raysan5)
*
**********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    float screenWidth = 800;
    float screenHeight = 600;
    
    SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(screenWidth, screenHeight, "raygui - portable window");

    // General variables
    Vector2 mousePosition = { 0 };
    Vector2 windowPosition = { 500, 200 };
    Vector2 panOffset = mousePosition;
    bool dragWindow = false;
    
    SetWindowPosition(windowPosition.x, windowPosition.y);
    
    bool exitWindow = false;
    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    float gameHeight;
    float gameWidth;
    Rectangle gameRectangle = { 100, 100, 200, 80 };

    // Main game loop
    while (!exitWindow && !WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        mousePosition = GetMousePosition();
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (CheckCollisionPointRec(mousePosition, (Rectangle){ 0, 0, screenWidth, 20 }))
            {
                dragWindow = true;
                panOffset = mousePosition;
            }
        }

        if (dragWindow)
        {            
            windowPosition.x += (mousePosition.x - panOffset.x);
            windowPosition.y += (mousePosition.y - panOffset.y);
            
            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) dragWindow = false;

            SetWindowPosition(windowPosition.x, windowPosition.y);
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            exitWindow = GuiWindowBox((Rectangle){ 0, 0, screenWidth, screenHeight }, "INVADERS EDITOR");
            DrawRectangle(20, 40, screenWidth-150, screenHeight-60, LIGHTGRAY);
            DrawText("Game Screen", 20, 40, 10, BLACK);

            gameHeight = GuiSliderBar((Rectangle){ screenWidth-140, 60, 120, 20 }, "Height", "", gameHeight, 0, 450);
            gameWidth = GuiSliderBar((Rectangle){ screenWidth-140, 100, 120, 20 }, "Width", "", gameWidth, 0, 450);

            if (GuiButton((Rectangle){ screenWidth-140, 140, 115, 30 }, "ADD ACTOR")) { }
            if (GuiButton((Rectangle){ screenWidth-140, 180, 115, 30 }, "SELECT ACTOR")) { }


            DrawRectangleLinesEx(gameRectangle, 1, RED);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
