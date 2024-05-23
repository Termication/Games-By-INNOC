#include "fire.hpp"

Fire::Fire(Vector2 position, int speed){
    this -> position = position;
    this -> speed = speed;
}

void Fire::Draw(){
//fire in form of rectangle
    DrawRectangle(position.x, position.y, 4, 15, {243, 216, 63, 255});
}

void Fire::Update(){
//for moving the fire upwards
    position.y += speed;
}
