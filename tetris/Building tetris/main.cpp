#include <iostream>
#include <raylib.h>
#include "grid.h"

using namespace std;

int main()
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris By INN.");
    SetTargetFPS(60);

    Grid grid; // Create a Grid object
    grid.Print(); // Just for testing purposes

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();

        EndDrawing();
    }

    CloseWindow();
}
