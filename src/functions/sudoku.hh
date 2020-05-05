#ifndef def_ottes_sudoku_hh
#define def_ottes_sudoku_hh
#include <cstdlib>

typedef int Sudoku[81];
size_t row_of(size_t const pos);
size_t column_of(size_t const pos);
size_t block_of(size_t const pos);
size_t next_empty(Sudoku const &sudoku);


#endif //def_ottes_sudoku_hh