#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game{
public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    void Draw();
    void HandleInput();
    Grid grid;

private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};
