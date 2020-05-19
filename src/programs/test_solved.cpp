#include "../functions/sudoku.hh"
#include <iostream>

using namespace std;

int main()
{
    string in_str;
    cin >> in_str;

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
        else
        {
            cerr << "Invalid input: " << letter << '\n';
            return 0;
        }
    }
    
    //checks if sudoku is solved or not
    if (solved(sudoku_arr))
    {
        cout << "Wihoo\n";
    }
    else if (! solved(sudoku_arr))
    {
        cout << ":,(\n";
    }
}
