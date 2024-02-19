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
    Font font1 = LoadFontEx("font/AtariClassicChunky-PxXP.ttf", 64, 0, 0);

    Game game = Game();

    while (!WindowShouldClose()) {
        game.HandleInput();
        if(EventTriggered(0.2)){
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "next", {370, 175}, 38, 2, WHITE);
        if(game.gameOver){
            DrawTextEx(font, "game over", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font1, scoreText, {300 + (170 - textSize.x) / 2, 65}, 20, 2, WHITE);

        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}
