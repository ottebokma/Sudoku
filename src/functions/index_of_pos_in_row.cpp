#include "sudoku.ih"

//Gives the index (in the sudoku) for a position in a row
size_t index_of_pos_in_row(size_t row, size_t pos_in_row)
{
    return row * 9 + pos_in_row;
}