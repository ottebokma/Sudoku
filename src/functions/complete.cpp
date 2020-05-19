#include "sudoku.ih"

//Checks if the sudoku is complete
bool complete(Sudoku const &sudoku)
{
    return next_empty(sudoku) == 81;
}