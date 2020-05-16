#include "sudoku.ih"

size_t index_of_pos_in_block(size_t block, size_t pos_in_block)
{
    // Which column and row (of blocks, so 0-2) the block is in.
    size_t block_column = block % 3;
    size_t block_row = block / 3;

    // Which column and row (of fields, so 0-9) the field is in.
    size_t column;
    size_t row;

    column = block_column * 3 + pos_in_block % 3;
    row = block_row * 3 + pos_in_block / 3;

    // Compute index of field.
    return row * 9 + column;

    
    
}

/**
   The 3*3 blocks of the sudoku are numbered 0-2 from left to right in the top
   row, then 3-5 on the next row, etc. The fields within each block are numbered
   similarly.

   This function will compute the index of a field into the sudoku as a whole,
   given its block number and its number within the block. So e.g. block 3 (on
   the second row) 's second field has index 28.
 */
