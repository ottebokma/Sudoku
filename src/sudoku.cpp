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

    //Checks if the input string length is correct
    if (in_str.length() != 81)
    {
        cerr << "Invalid input: wrong length\n";
        return E_INVALIDINPUT;
    }
        

    int sudoku_arr[81]; //Variable for array

    // Convert input string to array
    for (size_t pos = 0; pos != 81; ++pos)
    {
        char const letter = in_str[pos];    //Makes input from position as char const
        if (letter == '.')  //If the character i '.' puts 0 in array
            sudoku_arr[pos] = 0;
        else if ('1' <= letter and letter <= '9')   //If 1 <= character <= 9 puts that number in array
            sudoku_arr[pos] = letter - '0';
        else //If none of the statements apply give error code for invalid inpus
        {
            cerr << "Invalid input: " << letter << '\n';
            return E_INVALIDINPUT;
        }
    }

    string sudoku_str(81,'.'); //Variable for new string

    //Convert array to string
    for (size_t pos = 0; pos != 81; ++pos)
    {
        int const num = sudoku_arr[pos]; 
        if (1 <= num and num <= 9)  //If 1 <= num <= 9 puts num in string as char
            sudoku_str[pos] = num + '0';
        else if (num != 0) //If num is not '.' or 1-9 give error code for invalid computation
        {
            cerr << "Invalid computation: number not 1-9 in array\n";
            return E_INVALIDCOMPUTATION;
        }
        
    }

    //Checks if input and output string match
    if (in_str == sudoku_str) //If strings match print this
        cout << "Yayyy\n";
    else //If strings do not match print  this
        cout << "ÄÄÄÄÄÄÄÄHHHHH NÖÖÖÖÖÖÖÖ\n";
    
    cout << in_str << '\n';
    cout << sudoku_str << '\n';
}