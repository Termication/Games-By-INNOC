#include "colors.h"

const Color darkGrey = {26, 31, 40, 255};
const Color green = {47, 230, 23, 255};
const Color red = {231, 19, 19, 255};
const Color orange = {226, 116, 18, 255};
const Color yellow = {238, 235, 6, 255};
const Color purple = {165, 1, 247, 255};
const Color cyan = {21, 205, 210, 255};
const Color blue = {14, 63, 216, 255};
const Color lightBlue = {59, 85, 162, 255};
const Color darkBlue = {44, 44, 127, 255};

std::vector<Color> GetCellColors(){

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}
