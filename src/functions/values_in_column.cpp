#include "sudoku.ih"

vector<int> values_in_column(Sudoku const &sudoku, size_t const column)
{
    vector<int> values;
    
    for (size_t pos_in_column = 0; pos_in_column < 9; pos_in_column++)
    {
        size_t const index = index_of_pos_in_column(column, pos_in_column);
        int const value = sudoku[index];
        if (value != 0)
            values.push_back(value);
    }
    return values;
}