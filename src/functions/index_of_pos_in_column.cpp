#include "sudoku.ih"

size_t index_of_pos_in_column(size_t column, size_t pos_in_column)
{
    return column + pos_in_column * 9;
}