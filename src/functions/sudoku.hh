#ifndef def_ottes_sudoku_hh
#define def_ottes_sudoku_hh
#include <cstdlib>
#include <vector>

typedef int Sudoku[81];

size_t row_of(size_t const pos);

size_t column_of(size_t const pos);

size_t block_of(size_t const pos);

size_t next_empty(Sudoku const &sudoku);

bool complete(Sudoku const &sudoku);

size_t index_of_pos_in_row(size_t row, size_t pos_in_row);

size_t index_of_pos_in_column(size_t column, size_t pos_in_column);

#endif //def_ottes_sudoku_hh