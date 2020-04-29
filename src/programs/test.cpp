/**
   This is just a test to show that *.cpp-files in the 'programs' directory will
   be built into programs by the Makefile. So it is easy to do a quick test here
   instead of in sudoku.cpp.

   (And we see an example of a string literal:
    https://en.cppreference.com/w/cpp/language/string_literal )
 */
#include <iostream>

int main()
{
    std::cout <<
        R"(
    Just testing.
    Nothing to see here, folks.
    Please move on.

)";
}
