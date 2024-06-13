#include <iostream>
#include <raylib.h>
#include "Obstacle.hpp"
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
    Obstacle obstacle = Obstacle({100, 100});

    //Main Game loop
    while(WindowShouldClose() == false){

        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);
        game.Draw();
        obstacle.Draw();

        EndDrawing();
    }


    CloseWindow();
}
