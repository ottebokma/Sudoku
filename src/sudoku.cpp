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
        

    int sudoku_arr[81];

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
            return E_INVALIDINPUT;
        }
    }

    size_t ne = next_empty(sudoku_arr);
  
    cout << "Next empty field at index " << ne << '\n';

    string sudoku_str(81,'.');

    //Convert array to string
    //So that the output has the same type as the input
    for (size_t pos = 0; pos != 81; ++pos)
    {
        int const num = sudoku_arr[pos]; 
        if (1 <= num and num <= 9)
            sudoku_str[pos] = num + '0';
        else if (num != 0)
        {
            cerr << "Invalid computation: number not 1-9 in array\n";
            return E_INVALIDCOMPUTATION;
        }
        
    }

    //Checks if input and output strings match
    cout << ((in_str == sudoku_str) ? "Yayyy" : "ÄÄÄÄÄÄÄÄHHHHH NÖÖÖÖÖÖÖÖ") << '\n';
    
    cout << in_str << '\n';
    cout << sudoku_str << '\n';
}