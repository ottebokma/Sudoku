#include "sudoku.ih"

std::ostream &operator<<(std::ostream &outs, Sudoku const &sudoku)
{
for (size_t ix =0 ; ix != 81; ++ ix)
outs << sudoku[ix];
return outs;
}