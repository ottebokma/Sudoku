#include "sudoku.ih"
size_t next_empty(Sudoku const &sudoku)
{
    for (size_t pos = 0; pos != 81 ; ++pos)
    {
        if (sudoku [pos] == 0)
            return pos;
    }
    return 81;
}