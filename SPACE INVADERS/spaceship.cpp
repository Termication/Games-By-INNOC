#include "spaceship.hpp"
#include <raylib.h>

Spaceship::Spaceship()
{
    image = LoadTexture("Graphics/spaceship.png");
    position.y = 100;
    position.x = 100;
}

Spaceship::~Spaceship()
{
    UnloadTexture(image);
}

void Spaceship::Draw()
{
    DrawTextureV(image, position, WHITE);
}
