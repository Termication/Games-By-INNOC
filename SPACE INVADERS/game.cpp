#include "game.hpp"


Game::Game()
{

}

Game::~Game()
{
}

void Game::Update(){
    for(auto& fire: spaceship.fires){
        fire.Update();
    }
}

void Game::Draw(){
    spaceship.Draw();

    for(auto& fire: spaceship.fires){
        fire.Draw();
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
