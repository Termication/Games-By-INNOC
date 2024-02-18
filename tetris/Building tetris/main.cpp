#include <iostream>
#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

using namespace std;

int main()
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris By INN.");
    SetTargetFPS(60);

    Grid grid; // Create a Grid object
    grid.Print(); // Just for testing purposes

    ZBlock block = ZBlock();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        block.Draw();

        EndDrawing();
    }

    CloseWindow();
}
