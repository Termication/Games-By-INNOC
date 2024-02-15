#include "snake_game.h"
#include <cstddef>
#include <string>

SnakeGame::SnakeGame() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake source code by Inn.");
    SetTargetFPS(10);

    snake.push_back({SCREEN_WIDTH / (2 * GRID_SIZE), SCREEN_HEIGHT / (2 * GRID_SIZE)});
    direction = Direction::RIGHT;
    food = {GetRandomValue(0, SCREEN_WIDTH / GRID_SIZE - 1) * GRID_SIZE,
            GetRandomValue(0, SCREEN_HEIGHT / GRID_SIZE - 1) * GRID_SIZE};
    gameOver = false;
    score = 0;
}

void SnakeGame::Run() {
      while (!WindowShouldClose() && !gameOver) {
        Update();
        Draw();
    }

    CloseWindow();
}

void SnakeGame::Update() {
    if (IsKeyPressed(KEY_UP) && direction != Direction::DOWN)
        direction = Direction::UP;
    else if (IsKeyPressed(KEY_DOWN) && direction != Direction::UP)
        direction = Direction::DOWN;
    else if (IsKeyPressed(KEY_LEFT) && direction != Direction::RIGHT)
        direction = Direction::LEFT;
    else if (IsKeyPressed(KEY_RIGHT) && direction != Direction::LEFT)
        direction = Direction::RIGHT;

    // Move snake
    for (int i = snake.size() - 1; i > 0; --i) {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }

    // Update head
    switch (direction) {
        case Direction::UP:
            snake[0].y -= 1;
            break;
        case Direction::DOWN:
            snake[0].y += 1;
            break;
        case Direction::LEFT:
            snake[0].x -= 1;
            break;
        case Direction::RIGHT:
            snake[0].x += 1;
            break;
    }

    // Check collision with walls
    if (snake[0].x < 0 || snake[0].x >= SCREEN_WIDTH / GRID_SIZE ||
        snake[0].y < 0 || snake[0].y >= SCREEN_HEIGHT / GRID_SIZE)
        gameOver = true;

    // Check collision with self
    for (size_t i = 1; i < snake.size(); ++i) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            gameOver = true;
    }

    // Check collision with food
    if (snake[0].x == food.x / GRID_SIZE && snake[0].y == food.y / GRID_SIZE) {
        snake.push_back({food.x / GRID_SIZE, food.y / GRID_SIZE});
        food = {GetRandomValue(0, SCREEN_WIDTH / GRID_SIZE - 1) * GRID_SIZE,
                GetRandomValue(0, SCREEN_HEIGHT / GRID_SIZE - 1) * GRID_SIZE};
    }
        // Check collision with food
     if (snake[0].x == food.x / GRID_SIZE && snake[0].y == food.y / GRID_SIZE) {
        snake.push_back({food.x / GRID_SIZE, food.y / GRID_SIZE});
        food = {GetRandomValue(0, SCREEN_WIDTH / GRID_SIZE - 1) * GRID_SIZE,
                GetRandomValue(0, SCREEN_HEIGHT / GRID_SIZE - 1) * GRID_SIZE};
        score++; // Increment score when the snake eats the food
    }
}

void SnakeGame::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw food
    DrawRectangle(food.x, food.y, GRID_SIZE, GRID_SIZE, RED);

    DrawText(("Score: " + std::to_string(score)).c_str(), 10, 10, 20, BLACK);

    // Draw snake
    for (size_t i = 0; i < snake.size(); ++i) {
        // Calculate snake segment position
        float posX = snake[i].x * GRID_SIZE + GRID_SIZE / 2.0f;
        float posY = snake[i].y * GRID_SIZE + GRID_SIZE / 2.0f;

        // Calculate snake segment color
        Color color;
        if (i == 0) {
            color = DARKGREEN;
        } else {
            color = GREEN;
        }

        // Draw snake segment
        DrawRectangle(posX - GRID_SIZE / 2.0f, posY - GRID_SIZE / 2.0f, GRID_SIZE, GRID_SIZE, color);

        // Draw border around snake segment
        DrawRectangleLines(posX - GRID_SIZE / 2.0f, posY - GRID_SIZE / 2.0f, GRID_SIZE, GRID_SIZE, BLACK);
    }


    EndDrawing();
}


