#include <iostream>
#include <string>

enum {
    E_INVALIDINPUT = 1
};

using namespace std;

int main()
{
    string in_str;
    cin >> in_str;
    // TO DO
    //Ceck if input length is correct

    int sudoku_arr[81];

    for (int i = 0; i != 81; ++i)
    {
        char const letter = in_str[i];
        if (letter == '.')
            sudoku_arr[i] = 0;
        else if ('1' <= letter and letter <= '9')
            sudoku_arr[i] = letter - '0';
        else
        {
            cerr << "Invalid input: " << letter << '\n';
            return E_INVALIDINPUT;
        }
    }

    string sudoku_str(81,'.');

    for (int i = 0; i != 81; ++i)
    {
        int const num = sudoku_arr[i];
        if (1 <= num and num <= 9)
            sudoku_str[i] = num + '0';
    }

    cout << sudoku_str << '\n';
}