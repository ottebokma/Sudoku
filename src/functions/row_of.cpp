#include "sudoku.ih"

//Checks which row a position is in
size_t row_of(size_t const pos)
{
	return pos / 9;
}