#include "fire.hpp"

Fire::Fire(Vector2 position, int speed){
    this -> position = position;
    this -> speed = speed;
}

void Fire::Draw(){
    DrawRectangle()
}
