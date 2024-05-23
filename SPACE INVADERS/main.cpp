#include <iostream>
#include <raylib.h>
#include "game.hpp"


using namespace std;

int main()
{
    Color grey = {29, 29, 27, 255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "Space Invaders by INN");
    SetTargetFPS(60);

    Game game;

    while(WindowShouldClose() == false){

        game.HandleInput();

        BeginDrawing();
        ClearBackground(grey);

        game.Draw();

        EndDrawing();
    }


    CloseWindow();
}
