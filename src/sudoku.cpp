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

    for (int pos = 0; pos != 81; ++pos)
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

    string sudoku_str(81,'.');

    for (int pos = 0; pos != 81; ++pos)
    {
        int const num = sudoku_arr[pos];
        if (1 <= num and num <= 9)
            sudoku_str[pos] = num + '0';
        //TO DO
        //Check range
    }

    cout << sudoku_str << '\n';
}