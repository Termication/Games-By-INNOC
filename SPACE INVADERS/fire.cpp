#include "fire.hpp"

Fire::Fire(Vector2 position, int speed){
    this -> position = position;
    this -> speed = speed;
}

void Fire::Draw(){
    DrawRectangle(position.x, position.y, 4, 15, {243, 216, 63, 255});
}
