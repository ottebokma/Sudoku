#include "functions/sudoku.hh"
#include <iostream>
#include <string>


enum {
    E_INVALIDINPUT = 1,
    E_INVALIDCOMPUTATION
};


using namespace std;

int main()
{
    string in_str;
    cin >> in_str;
        
    //Checks if string length is correct, to find possible issue
    if (in_str.length() != 81)
    {
        cerr << "Invalid input: wrong length\n";
        return E_INVALIDINPUT;
    }
        
    Sudoku sudoku_arr;

    //Convert input string to array
    //So that the program can use the input
    for (size_t pos = 0; pos != 81; ++pos)
    {
        char const letter = in_str[pos];
        if (letter == '.')
            sudoku_arr[pos] = 0;
        else if ('1' <= letter and letter <= '9')
            sudoku_arr[pos] = letter - '0';
        //Checks that there are only numbers in the input
        else
        {
            cerr << "Invalid input: " << letter << '\n';
            return E_INVALIDINPUT;
        }
    }

    //Checks that the input sudoku is valid
    if (! valid(sudoku_arr))
    {
        cerr << "Invalid numbers in input sudoku\n";
        return E_INVALIDINPUT;
    }

    //Solves the sudoku if it is solvable
    if (solve(sudoku_arr))
        return 0;
}