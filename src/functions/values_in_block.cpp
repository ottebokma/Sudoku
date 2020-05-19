#include "sudoku.ih"

//returns the values that are i a particular block
vector<int> values_in_block(Sudoku const &sudoku, size_t const block)
{
    vector<int> values;
    
    for (size_t pos_in_block = 0; pos_in_block < 9; pos_in_block++)
    {
        size_t const index = index_of_pos_in_block(block, pos_in_block);
        int const value = sudoku[index];
        if (value != 0)
            values.push_back(value);
    }
    return values;
}