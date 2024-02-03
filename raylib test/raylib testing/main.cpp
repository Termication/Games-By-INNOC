#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define BALL_RADIUS 20
#define BALL_SPEED 5

int main() {
    // Initialization
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "INN.. Bouncing Ball");
    SetTargetFPS(60);

    // Ball properties
    Vector2 ballPosition = {(float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2};
    Vector2 ballSpeed = {BALL_SPEED, BALL_SPEED};

    while (!WindowShouldClose()) {
        // Update
        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        // Bounce off the walls
        if ((ballPosition.x + BALL_RADIUS) >= SCREEN_WIDTH || (ballPosition.x - BALL_RADIUS) <= 0) {
            ballSpeed.x *= -1;
        }
        if ((ballPosition.y + BALL_RADIUS) >= SCREEN_HEIGHT || (ballPosition.y - BALL_RADIUS) <= 0) {
            ballSpeed.y *= -1;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the ball
        DrawCircleV(ballPosition, BALL_RADIUS, RED);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
