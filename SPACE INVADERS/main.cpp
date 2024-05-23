#include <iostream>
#include <raylib.h>
#include "game.hpp"
#include "fire.hpp"


using namespace std;

int main()
{
    Color grey = {29, 29, 27, 255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "Space Invaders by INN");
    SetTargetFPS(60);

    Game game;
    Fire fire = Fire({100, 100}, -7);

    while(WindowShouldClose() == false){

        game.HandleInput();
        fire.Update();

        BeginDrawing();
        ClearBackground(grey);

        game.Draw();
        fire.Draw();

        EndDrawing();
    }


    CloseWindow();
}
