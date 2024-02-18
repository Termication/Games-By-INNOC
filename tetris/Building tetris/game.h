#pragma once
#include "grid.h"
#include "block.cpp"

class Game{
public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlock();
    Grid grid;

private:
    std::vector<Block> blocks;
};
