#pragma once
#include <raylib.h>

class Fire {
    public:
        Fire(Vector2 position, int speed);
        void Update();
        void Draw();
    private:
        Vector2 position;
        int speed;

};
