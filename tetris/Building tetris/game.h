#pragma once
#include "grid.h"
#include "block.cpp"

class Game{
public:
    Game();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    Grid grid;

private:
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};
