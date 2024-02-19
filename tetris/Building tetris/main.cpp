#include <iostream>
#include <raylib.h>
#include "game.h"

using namespace std;

double lastUpdateTime = 0;

bool EventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(500, 620, "Tetris By INN.");
    SetTargetFPS(60);

    Font font = LoadFontEx("font/BotsmaticOutline-anZg.ttf", 64, 0, 0);

    Game game = Game();

    while (!WindowShouldClose()) {
        game.HandleInput();
        if(EventTriggered(0.2)){
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}
