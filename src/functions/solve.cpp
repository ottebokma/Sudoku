#include "sudoku.ih"

bool solve(Sudoku &sudoku)
{
    if (solved(sudoku))
    {
        cout << sudoku << '\n';
        return true;
    }

    if (complete(sudoku))
        return false;
    
    int const index_empty = next_empty(sudoku);

    for (size_t num = 1; num < 10 ; ++num)
    {
        sudoku[index_empty] = num;

        if (valid(sudoku))
            solve(sudoku);
    }

    sudoku[index_empty] = 0;
    return false;
}