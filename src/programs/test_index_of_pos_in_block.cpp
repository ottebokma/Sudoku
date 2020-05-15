#include "../functions/sudoku.hh"
#include <iostream>

int main()
{
    for (size_t block = 0; block < 9; block++)
    {
        for (size_t pos_in_block = 0; pos_in_block < 9; pos_in_block++)
        {
            std::cout << index_of_pos_in_block(block, pos_in_block) << " ";
        }
        std::cout << '\n';
    }
    
}