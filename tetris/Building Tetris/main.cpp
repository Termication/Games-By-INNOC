#include <iostream>
#include <raylib.h>

using namespace std;

int main()
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris By INN.");
    SetTargetFPS(60);

    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(darkBlue);

        EndDrawing();
    }

}
