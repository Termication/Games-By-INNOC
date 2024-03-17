#include <iostream>
#include <raylib.h>

using namespace std;

class Ball{
  public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw(){
        DrawCircle(x, y, radius, WHITE);
    }

    void Update(){
        x += speed_x;
        y += speed_y;

        if (y + radius >= GetScreenHeight() || y - radius <= 0){
            speed_y *= - 1;
        }
        if(x + radius >= GetScreenWidth() || x - radius <= 0){
            speed_x *= -1;
        }
    }
};

class Paddle{
  protected:
    void LimitMovement(){
        if( y <= 0){
            y = 0;
        }
        if(y + height >= GetScreenHeight()){
            y = GetScreenHeight() - height;
        }
    }

  public:
    float x, y;
    float width, height;
    int speed;

    void Draw(){
        DrawRectangle(x,y,width,height, WHITE);
    }

    void Update(){
        if(IsKeyDown(KEY_UP)){
            y = y - speed;
        }
        if(IsKeyDown(KEY_DOWN)){
            y = y + speed;
        }
        LimitMovement();
    }

};

class AiPaddle : public Paddle{
 public:
    void Update(int ball_y){

        if(y + height/2 > ball_y){
            y = y - speed;
        }
        if(y + height/2 <= ball_y){
            y = y + speed;
        }
        LimitMovement();
    }
};
Ball ball;
Paddle player;
AiPaddle ai;

int main()
{
    const int screen_width = 1280;
    const int screen_height = 600;
    InitWindow(screen_width, screen_height, "Pong Game by INN");
    SetTargetFPS(60);

    //ball

    ball.radius = 20;
    ball.x = screen_width/2;
    ball.y = screen_height/2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    //player

    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - 10;
    player.y = screen_height/2 - player.height/2;
    player.speed = 6;

    //ai

    ai.height = 120;
    ai.width = 25;
    ai.x = 10;
    ai.y = screen_height/2 - ai.height/2;
    ai.speed = 6;

    while (WindowShouldClose() == false)
    {
         BeginDrawing();
         // updating methods
         ball.Update();
         player.Update();
         ai.Update(ball.y);

         //check for collisions
         if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height})){
            ball.speed_x *= -1;
         }
         if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{ai.x, ai.y, ai.width, ai.height})){
            ball.speed_x *= -1;
         }

         ClearBackground(BLACK);

         // drawing
         DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);
         ball.Draw();
         ai.Draw();
         player.Draw();


         EndDrawing();
    }

    CloseWindow();

    return 0;
}
