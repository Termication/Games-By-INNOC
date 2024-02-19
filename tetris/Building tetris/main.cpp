#include <iostream>
#include <raylib.h>
#include "game.h"

using namespace std;

int main()
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris By INN.");
    SetTargetFPS(60);

    Game game = Game();

    while (!WindowShouldClose()) {
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}
