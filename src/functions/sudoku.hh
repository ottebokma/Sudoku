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

size_t index_of_pos_in_block(size_t block, size_t pos_in_block);

bool valid(Sudoku const &sudoku);

std::vector<int> values_in_row(Sudoku const &sudoku, size_t const row);

std::vector<int> values_in_column(Sudoku const &sudoku, size_t const column);

std::vector<int> values_in_block(Sudoku const &sudoku, size_t const block);

bool solved(Sudoku const &sudoku);

#endif //def_ottes_sudoku_hh