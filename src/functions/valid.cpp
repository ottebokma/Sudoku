#include "sudoku.ih"

//checks if the sudoku is valid
bool valid(Sudoku const &sudoku)
{
    //checks if rows are valid
    for (size_t row = 0; row < 9; ++row)
    {
        vector<int> values = values_in_row(sudoku, row);
        sort(values.begin(), values.end());
        
        if (adjacent_find(values.begin(), values.end()) != values.end())
            return false;
    }

    //checks if columns are valid
    for (size_t column = 0; column < 9; ++column)
    {
        vector<int> values = values_in_column(sudoku, column);
        sort(values.begin(), values.end());
        
        if (adjacent_find(values.begin(), values.end()) != values.end())
            return false;
    }

    //checks if block are valid
    for (size_t block = 0; block < 9; ++block)
    {
        vector<int> values = values_in_block(sudoku, block);
        sort(values.begin(), values.end());
        
        if (adjacent_find(values.begin(), values.end()) != values.end())
            return false;
    }

    return true;
}