#include "sudoku.ih"

//Functions that allows the use of cout with the type "Sudoku" (an array)
std::ostream &operator<<(std::ostream &outs, Sudoku const &sudoku)
{
for (size_t ix =0 ; ix != 81; ++ ix)
outs << sudoku[ix];
return outs;
}