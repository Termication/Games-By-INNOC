#include <iostream>
#include <raylib.h>
#include "game.h"
#include "colors.h"

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
    InitWindow(500, 620, "Tetris By INN.");
    SetTargetFPS(60);

    Font font = LoadFontEx("font/BotsmaticDemo-MXOr.ttf", 64, 0, 0);

    Game game = Game();

    while (!WindowShouldClose()) {
        game.HandleInput();
        if(EventTriggered(0.2)){
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "score", {365, 15}, 38, 2, WHITE);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}
