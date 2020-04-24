#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int sudoku[81] = stoi(str);

    cout << sudoku << '\n';
}