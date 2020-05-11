#include "Sudoku.ih"

size_t index_of_pos_in_block(size_t block, size_t pos_in_block)
{
    size_t block_column = block % 3;
    size_t block_row = block / 3;

    size_t column_from = block_column * 3;
    size_t column_to = block_column * 3 + 2;

    size_t row_from = block_row * 3;
    size_t row_to = block_row * 3 + 2;

    for (row_from; row_to; pos_in_block++)
    {
        for (column_from; column_to; pos_in_block++)
        {
            return column_from + pos_in_block * 9;
        }
    }
    
}