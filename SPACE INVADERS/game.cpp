#include "game.hpp"
#include <iostream>

Game::Game()
{
    obstacles = CreateObstacles();
}

Game::~Game()
{
}

void Game::Update(){
// moving of the fired laser
    for(auto& fire: spaceship.fires){
        fire.Update();
    }
//delete inactive fires
    DeleteInactiveFire();
}

void Game::Draw(){
    spaceship.Draw();

    for(auto& fire: spaceship.fires){
        fire.Draw();
    }

    for(auto& obstacle : obstacles){
        obstacle.Draw();
    }
}

void Game::HandleInput(){
    if(IsKeyDown(KEY_LEFT)){
        spaceship.MoveLeft();
    } else if(IsKeyDown(KEY_RIGHT)){
        spaceship.MoveRight();
    } else if(IsKeyDown(KEY_SPACE)){
        spaceship.FireLaser();
    }
}

void Game::DeleteInactiveFire()
{
    //delete inactive fires
    for(auto it = spaceship.fires.begin(); it != spaceship.fires.end();){
        if(!it -> active){
            it = spaceship.fires.erase(it);
        } else{
            ++ it;
        }
    }
}

std::vector<Obstacle> Game::CreateObstacles(){
    int obstacleWidth = Obstacle::grid[0].size() * 3;
    float gap = (GetScreenWidth() - (4 * obstacleWidth))/5;

    //calculate horizontal position of each obstacle
    for(int i = 0; i < 4; i++){
        float offsetX = (i + 1) * gap + i * obstacleWidth;
        obstacles.push_back(Obstacle({offsetX, float(GetScreenHeight() - 100)}));
    }
    return obstacles;
}
