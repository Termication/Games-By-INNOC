#include "block.hpp"

Block::Block(Vector2 position){
    this -> position = position;

}
// implcementation to draw a block
void Block::Draw(){
    DrawRectangle(position.x, position.y, 3, 3, {243, 216, 63, 255});
}
