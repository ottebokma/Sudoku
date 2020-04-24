#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in_str;
    cin >> in_str;

    int sudoku = stoi(in_str);
    int sudoku_arr[81];

    

    //string sudoku_str = to_string(sudoku_arr);

    cout << sudoku_arr << '\n';
}