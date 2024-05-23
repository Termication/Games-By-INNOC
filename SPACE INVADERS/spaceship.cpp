#include "spaceship.hpp"
#include <raylib.h>


Spaceship::Spaceship()
{
    image = LoadTexture("Graphics/spaceship.png");
    position.x = (GetScreenWidth() - image.width)/2;
    position.y = GetScreenHeight() - image.height;
    lastFireTime = 0.0;
}

Spaceship::~Spaceship()
{
    UnloadTexture(image);
}

void Spaceship::Draw()
{
    DrawTextureV(image, position, WHITE);
}

void Spaceship::MoveLeft(){
    position.x -= 7;
    //prevent movement out of the window
    if(position.x < 0){
        position.x = 0;
    }
}

void Spaceship::MoveRight(){
    position.x += 7;
    //prevent movement out of the window
    if(position.x > GetScreenWidth() - image.width){
        position.x = GetScreenWidth() - image.width;
    }
}

void Spaceship::FireLaser(){
    //delay fire
    if(GetTime() - lastFireTime >= 0.35){
        fires.push_back(Fire({position.x + image.width/2 - 2, position.y}, -6));
        lastFireTime = GetTime();
    }
}
