#include "sudoku.ih"

//checks if a sudoku is solved
bool solved(Sudoku const &sudoku)
{
    if (valid(sudoku) == true and complete(sudoku) == true)
        return true;
    
    return false;
}