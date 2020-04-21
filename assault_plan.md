# Assault Plan

When learning C++, the question: "What is the result of this?" is not enough.
The question should be: "How does this work?"
This simple rule can in fact be used to distinguish those who may become
programmers from those who never will.

Hence, learning by example is only useful if you refrain from copying the
example until you understand how it works.
When in doubt, consult https://cppreference.com
Consider specifying 'site:cppreference.com' in Google.
Stackoverflow is only useful if you understand the questions.


## Basics (Types and Expressions):

C++ has operators:
https://en.cppreference.com/w/cpp/language/operator_precedence

For this project, we are probably not going to need functional casts and
C-style casts, indirection and address-of, co-await, dynamic (de)allocation,
pointer-to-member, three-way comparison, yield-expression and comma operators.
The throw operator: maybe.
So learn what the other operators mean:



    ::
    a++ a--
    a()
    a[]
    .
    ++a --a
    +a -a
    ! ~
    sizeof
    a*b a/b a%b
    a+b a-b
    << >>
    < <=
    > >=
    == !=
    &
    ^
    |
    &&
    ||
    a?b:c
    =
    += -=
    *= /= %=
    <<= >>=
    &= ^= |=


Every variable in C++ has a type. Nearly all expressions also have a type.
Some types are built in, such as these:
    bool
    char (signed, unsigned)
    int (short, long; signed, unsigned)
    float, double

Variables have scope. Outside their scope, they are not known to the compiler:

    {
        int a = 13;
	    {
	        int b = 42;
	    }
	    a = b; // Won't Compile because b is out of scope.
    }

Pointers and references exist, but we save them for later.

New types can be composed. Here is a point in 2D:

    struct Point
    {
        float x;
	    float y;
    }

Classes also exist, but that is for later.

Functions also have types, determined by their signatures. Here is a function
of type function-that-takes-two-Points-and-returns-a-float:

    float distance(Point a, Point b)
    {
         return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
    }

The Standard Template Library (STL) comes with a number of additional types,
one of which is std::string. A string is an object, and it has functions that
allow the user to manipulate it. See cppreference.

## I/O

C++ I/O works with streams. There are istreams (for input), ostreams (you
guessed it), and iostreams (for both). A stream is an object. Programs that
include the iostream header, automatically get cin (C's standard input), cout
(output), and cerr (another (unbuffered) output stream for errors.

The left shift operator (<<) is overloaded to insert data into a stream. The
right shift operator is overloaded to extract data from a stream.

What is the result type of the expression

    cout << "Oh " << " hi there!\n";
	
Does '<<' associate to the left or to the right?

For more on streams, see cppreference on std::istream.

### Partial Program

For the Sudoku solver, we need to be able to read and perhaps write Sudokus.
We are going to read them in the form of strings. But we are going to store them
in memory as an array of ints:

#### Assignment

Write a program that does the following:
* Read an entire line from cin into a std::string.
* Writes a copy of that same string to cout.
* Compares the copy and the original.
  If they are identical, the program should return 0.
  If they differ, the program should return some nonzero number.
* To test this, change a char in the copy before comparing.

#### Assignment

Consider the file sudoku_001.txt.
The program will from now on be called like this:

    ./sudoku < ../sudoku_001.txt

So the line we read represents a sudoku. We read it as a string, but we
are going to store it in memory as an array of ints:

    int sudoku[81];

(Be careful: an array in C++ cannot be copied as it can in Python.
This won't work:

    int copy_of_sudoku[81] = sudoku; // WC. C/C++ doesn't work that way.

After solving, we are going to write the sudoku again as a string.
So we need to convert from string to array of ints and back.

* Create a new branch in git to work in:
    git branch conversion
    git checkout conversion
* Modify the above program in the following way.
* After having read the line into a string, iterate over the string (char by
  char) as well as the array (int by int).
  When the char is a '.', put a 0 in the array.
  When the char is a '1', put a 1 in the array, when it is a '2', store a 2, etc.
  Note the distinction between '2' and 2.
  Thus we convert from ASCII to true numbers.
* Do not copy the original string any more. Instead, create a string of 81 dots ('.').
* Now iterate again, over the array and this new string. When the number in the
  array is a 0, don't change the char in the string. When it is not 0, write
  the proper char into the string. Again convert, this time from true numbers to ASCII.
* Write the created string to stdout.
* Keep the comparison in place.
* To test it, temporarily change one of the numbers in the array just before
  converting back to string.
* What happens if you make a number greater than 9?
