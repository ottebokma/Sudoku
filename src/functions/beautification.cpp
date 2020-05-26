#include "sudoku.ih"

//Makes the sudoku more human friendly
string beautification(Sudoku const &sudoku)
{
    string output("╔═══════╤═══════╤═══════╗\n");
    size_t ix = 0;
    while (true)
    {
        if (ix % 9 == 0)
            output += "║";
        (output += ' ') += to_string(sudoku[ix++]);
               
        if (ix % 9 == 0)
            output += " ║\n";
        else if (ix % 3 == 0)
            output += " │";

        if (ix >= 81)
            break;

        if (ix % 27 == 0)
            output += "╟───────┼───────┼───────╢\n";
    }

    output += "╚═══════╧═══════╧═══════╝\n";

    replace(output.begin(), output.end(), '0', '.');
    
    return output;
}
