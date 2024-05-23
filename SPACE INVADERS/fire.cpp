#include "fire.hpp"
#include <iostream>

Fire::Fire(Vector2 position, int speed){
    this -> position = position;
    this -> speed = speed;
    active = true;
}

void Fire::Draw(){
//fire in form of rectangle
    if(active)
        DrawRectangle(position.x, position.y, 4, 15, {243, 216, 63, 255});
}

void Fire::Update(){
//for moving the fire upwards
    position.y += speed;
    if(active){
        if(position.y > GetScreenHeight() || position.y < 0){
            active == false;
            // test fire deactive
            std::cout << "fire deactive" << std::endl;
        }
    }
}
