#include "sudoku.ih"

//checks if a sudoku is solved
bool solved(Sudoku const &sudoku)
{
    return valid(sudoku) and complete(sudoku);
}