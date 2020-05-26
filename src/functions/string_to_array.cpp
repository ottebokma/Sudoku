#include "sudoku.ih"

size_t string_to_array(string const input, size_t const pos)
{
    
    char const letter = input[pos];
    if (letter == '.')
        return 0;
    else if ('1' <= letter and letter <= '9')
        return letter - '0';
    //Checks that there are only numbers in the input
    else
    {
        cerr << "Invalid input: " << letter << '\n';
        return false;
    }
}