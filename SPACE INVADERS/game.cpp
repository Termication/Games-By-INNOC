#include "game.hpp"
#include <iostream>

Game::Game()
{

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
