#include "sudoku.ih"

size_t index_of_pos_in_block(size_t block, size_t pos_in_block)
{
    size_t block_column = block % 3;
    size_t block_row = block / 3;

    size_t column;
    size_t row;

    column = block_column * 3 + pos_in_block % 3;
    row = block_row * 3 + pos_in_block / 3;

    return row * 9 + column;

    
    
}