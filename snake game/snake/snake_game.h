#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include "raylib.h"
#include <vector>

#define GRID_SIZE 20
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

struct SnakeSegment {
    int x;
    int y;
};

enum class Direction { UP, DOWN, LEFT, RIGHT };

class SnakeGame {
public:
    SnakeGame();
    void Run();

private:
    void Update();
    void Draw();

    std::vector<SnakeSegment> snake;
    Direction direction;
    Vector2 food;
    bool gameOver;
    int score;
};

#endif // SNAKE_GAME_H

