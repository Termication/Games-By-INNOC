#pragma once
#include "spaceship.hpp"
#include "Obstacle.hpp"

class Game{
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
    private:
        Spaceship spaceship;
        void DeleteInactiveFire();
        std::vector<Obstacle> CreateObstacles();
        std::vector<Obstacle> obstacles;

};
