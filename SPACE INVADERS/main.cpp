#include <iostream>
#include <raylib.h>

using namespace std;

int main()
{
    Color grey = {29, 29, 27, 255};
    int windowWidth = 750;
    int windowHeight = 700;

    InitWindow(windowWidth, windowHeight, "Space Invaders by INN");
    SetTargetFPS(60);

    while(WindowShouldClose() == false){

        BeginDrawing();
        ClearBackground(grey);
        EndDrawing();
    }


    CloseWindow();
}
