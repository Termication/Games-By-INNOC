
#pragma once
#include <vector>
#include <raylib.h>


class Grid{
public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutSide(int row, int column);
    bool IsCellEmpty(int row, int column);
    int grid[20][10];

private:
    bool IsRowFull(int row);
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};
