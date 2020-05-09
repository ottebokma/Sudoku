#include "../functions/sudoku.hh"
#include <iostream>

int main()
{
    for (size_t column = 0; column < 9; column++)
    {
        for (size_t pos_in_column = 0; pos_in_column< 9; pos_in_column++)
        {
            std::cout << index_of_pos_in_column(column, pos_in_column) << " ";
        }
        std::cout << '\n';
    }
    
}