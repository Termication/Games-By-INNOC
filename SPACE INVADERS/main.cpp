#include <iostream>
#include <raylib.h>

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

    //Main Game loop
    while(WindowShouldClose() == false){

        BeginDrawing();
        ClearBackground(grey);
        
        EndDrawing();
    }


    CloseWindow();
}
