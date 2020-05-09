#include "sudoku.ih"

vector<int> values_in_row(Sudoku const &sudoku, size_t const row)
{
    vector<int> values;
    
    for (size_t pos_in_row = 0; pos_in_row < 9; pos_in_row++)
    {
        size_t const index = index_of_pos_in_row(row, pos_in_row);
        int const value = sudoku[index];
        if (value != 0)
            values.push_back(value);
    }
    return values;
}