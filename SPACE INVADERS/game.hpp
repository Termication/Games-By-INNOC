#pragma once

class Game{
    public:
        Game();
        ~Game();
        void Draw();
        void Update();
        void HandleInput();
    private:
        Spaceship spaceship;

};
