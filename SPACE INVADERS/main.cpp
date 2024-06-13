#include <iostream>
#include <raylib.h>
#include "game.hpp"

using namespace std;

int main()
{
    //background color
    Color grey = {29, 29, 27, 255};
    int windowWidth = 750;
    int windowHeight = 700;

    //Window declare
    InitWindow(windowWidth, windowHeight, "Space Invaders by INN");
    SetTargetFPS(60);

    Game game;

    //Main Game loop
    while(WindowShouldClose() == false){

        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);
        game.Draw();


        EndDrawing();
    }


    CloseWindow();
}
