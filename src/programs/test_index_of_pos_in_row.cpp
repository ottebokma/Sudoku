#include "../functions/sudoku.hh"
#include <iostream>

int main()
{
    for (size_t row = 0; row < 9; row++)
    {
        for (size_t pos_in_row = 0; pos_in_row < 9; pos_in_row++)
        {
            std::cout << index_of_pos_in_row(row, pos_in_row) << " ";
        }
        std::cout << '\n';
    }
    
}