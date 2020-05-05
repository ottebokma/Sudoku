#include "sudoku.ih"

bool complete(Sudoku const &sudoku)
{
    return next_empty(sudoku) == 81;
}