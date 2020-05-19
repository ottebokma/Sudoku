#include "sudoku.ih"

//Checks in which column a position is
size_t column_of(size_t const pos)
{
    return pos % 9;
}