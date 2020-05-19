#include "sudoku.ih"

//Checks in which block a position is
size_t block_of(size_t const pos)
{
    size_t const block_row = row_of(pos) / 3;
    size_t const block_column = column_of(pos) / 3;
    
    return block_column + block_row * 3;
}