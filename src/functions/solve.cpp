#include "sudoku.ih"

//Solves the sudoku
bool solve(Sudoku &sudoku)
{   
    //Returns true if the sudoku is solved
    if (solved(sudoku))
    {
        cout << beautification(sudoku) << '\n';
        return true;
    }

    //Checks that the sudoku is not complete even though it is not solved
    if (complete(sudoku))
        return false;
    
    int const index_empty = next_empty(sudoku);

    //Places values in the empty slots in the sudoku
    for (size_t num = 1; num < 10 ; ++num)
    {
        sudoku[index_empty] = num;

        if (valid(sudoku))
            solve(sudoku);
    }

    sudoku[index_empty] = 0;
    return false;
}