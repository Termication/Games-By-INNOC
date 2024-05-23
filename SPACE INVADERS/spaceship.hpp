#pragma once
#include <raylib.h>
#include "fire.hpp"
#include <vector>

class Spaceship{
    public:
        Spaceship();
        ~Spaceship();
        void Draw();
        void MoveRight();
        void MoveLeft();
        void FireLaser();
        std::vector<Fire> fires;


    private:
        Texture2D image;
        Vector2 position;
};
