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

## Planning

* Week 1: Git. Basics. I/O and strings. ASCII.
          Result: a program that reads/writes sudokus.
* Week 2: Functions. Compiling/linking. Headers. Program layout.
          Result: a program that is readable and easily extended.
* Week 3: More functions. Recursion. Brute-forcing.
          Result: a program that solves sudokus.
* Week 4: Improvements: readability, efficiency.
          Result: to be determined. Faster solving? Nicer input/output format?
* Week 5: Reserved.

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
* If you never used git during the work, now is the time to add all the files
  you worked on and commit the changes. Only add sources, not the executable
  programs the compiler builds for you.
* After that, switch back to the 'master' branch, merge the 'conversion' branch,
  and then delete the 'conversion' branch as it's no longer used.


## Functions

Using functions, the programmer can cut large pieces of code into smaller ones.
This serves several purposes:

* Re-use of code. A function can be called in multiple places.
* Documentation. Calling a function called 'distance' is clearer than an
  expression that computes the distance.
* Reducing scope. The code in a function will be influenced only by its
  parameters. It will influence other code only through the return value.
  (This is why global variables are bad.)

In C++, function arguments are passed by value. That is, given this function

    Point translate(Point a)
    {
	     a.x += 2;
		 a.y += 2;
		 return a;
    }

the following function call will not change Origin:

    Point origin(0, 0);
	Point tutu = translate(origin);

That is because 'a' in the parameter list of 'translate' is a copy of 'origin'.
If we *want* to influence the original, we can give the function a reference parameter:

    Point translate_with_change(Point &a)
    {
	     a.x += 2;
		 a.y += 2;
		 return a;
    }

If this is the function being called, 'origin' *will* change.


#### Assignment

* Create another git branch. Once you are done with this assignment, merge and delete it.
* Create functions to
  * read a string from cin,
  * convert a single char from ASCII to an int,
  * convert an int to an ASCII char,
  * convert from a string to an array of ints,
  * convert from an array of ints to a string,
  * write a string to cout.
* Make your program more readable by using all these functions.


### Multiple files

You can keep all your functions in a single file, and scroll your fingers off
moving between them. Or you can put each function in a file of its own. The
latter saves compilation time too: when you recompile one file, all the other
functions in other files don't have to be touched.

But because of the 2-stage process that building a program is, you'll need a
header file as well, which is a sort of index or directory file that lists only
the types of the functions, but not what they do exactly.

#### Example

Here's a little example. We have a program 'main.cpp' that uses two functions:

    #include "my_functions.hh"

    int main()
    {
        return triple_plus_one(13) - halve(42);
    }

##### Header file

This program includes the header file "my_functions.hh", which has only
declarations_ of the functions. That is, it tells what they look like from the
outside, but not how they work (because the function bodies aren't there.

    #ifndef def_my_functions_hh
    #define def_my_functions_hh

    int triple_plus_one(int value);
    int halve(int value);

    #endif //def_my_functions_hh

##### Compiling
(Ignore the lines that start with a '#' for now. We'll talk about them later.)
With this header file in place, the main.cpp can be compiled into a so-called
object file, but the program 'main' cannot yet be built completely:

    g++ -Wall -std=c++2a -c -o main.o main.cpp

This gives us an object-file, in which the compiler has processed main.cpp, but
left gaps open for links to the bodies of the two functions of which it doesn't
know what they do yet. To build main, it needs to fill in those gaps, and to do
that, it needs a library that contains the bodies of these functions. So we are
going to build that, too.

Of course we also have the files with the functions. triple_plus_one.cpp:

	int triple_plus_one(int value)
	{
	    return 3 * value + 1;
	}

and halve.cpp:

	int halve(int value)
	{
		return value / 2;
	}

So we can compile those too, using much the same command as for compiling main.o
(only the file names differ):

	g++ -Wall -std=c++2a -c -o triple_plus_one.o triple_plus_one.cpp
	g++ -Wall -std=c++2a -c -o halve.o halve.cpp

##### Creating the static library

Then we join all the object files into a static library, which is basically just
a file in which the objects and the functions (and variables, and types) they
hold can easily be found by the linker.

	ar rcs libmy_functions.a triple_plus_one.o halve.o

Now we must still _link_ main.o against the library to build main:

    g++ -Wall -std=c++2a -o main main.o -L. -lmy_functions

##### Why all this hassle?

Let's say that the function 'halve' is used in seven other functions. If we
include its body every time it is used, we must compile it seven times to build
the project. More if those other functions themselves are used in multiple
places.

With the above approach of including header files, halve.cpp has to be compiled
only once. When it is changed, we recompile it and update its object in the
library. After that, programs that use it only have to be linked again. They
don't have to be recompiled. That saves much time.

##### Internal headers

It happens often that in source files like halve.cpp we want to include header
files as well. Perhaps my_functions.hh has an enum E_IO that we want to use. Or
perhaps we want to include iostream in order to use cout or cerr for debugging.
It also happens often that we want to do that in many source files. And we don't
want to repeat ourselves, so we write all those includes in one _internal_
header file my_functions.ih:

    #include "my_functions.hh"
	#include <iostream>

	using namespace std;

and then include that into the source files, e.g. halve.cpp becomes:

    #include "my_functions.ih"

	int halve(int value)
	{
		return value / 2;
	}

This is convenient. We can use 'cout' without the 'std::' prefix in halve.cpp
(and in all other function source files), but we are not polluting main.cpp with
namespace std. We can use iostream in the function source files, but we don't
force the compiler to read through that (big!) file when compiling main.o.

(Note that we do force the compiler to read through the iostream header for each
function source file it compiles. There is a solution for that in the form of
precompiled headers. But that is outside the scope of this little project.)

##### Header Guards

Remember those lines with '#' in my_functions.hh that we said we would talk
about, like these?:

    #ifndef def_my_functions_hh
    #define def_my_functions_hh

    #endif //def_my_functions_hh

Those are header guards. With the function declarations currently in
my_functions.hh, nothing can go wrong. You can declare a function as many times
as you like. But it is also practical to be able to put type definitions in header files, like this one:

    struct Point
    {
        double x;
        double y;
    };

That is a _definition_, not a declaration. (If the header file contains any
functions that take a Point as parameter, the compiler must know how big a Point
is, and for that the declaration of Point is not enough. It must have the
definition.)

So let's say Point's definition is in 'my_functions.hh'. And main.cpp includes
'my_functions.hh', but it also includes 'more_functions.hh'. But unfortunately,
'more_functions.hh' _also_ has functions that use Point, so 'more_functions.hh'
also includes 'my_functions.hh':

    main.cpp <--------------------------------  my_functions.hh
             <---*                             /
                  \                           /
                   *--- more_functions.hh <--*

Now we have a problem, because the definition of Point is available to main
twice: once via more_functions.hh, and once from my_functions.hh directly.
And multiple definitions of the same thing are not allowed in C++.

Enter those '#' lines called header guards. Even before compilation happens, all
source and headers files are treated by the so-called preprocessor. When it sees
the #ifndef line, it checks whether it knows the preprocessor definition
(completely unrelated to a C++ definition) of def_my_functions_hh. The first
time it reads my_function.hh, it doesn't know. So it goes on, and on the next
line (#define), it sees the definition given.

Next time it sees my_function.hh, when it checks whether it knows
def_my_functions_hh, it does know. So it skips through to the next #endif.

Conveniently, this means that main.cpp can include both my_functions.hh and more
function.hh, but the bulk of my_functions.hh is still only going to be processed
once, because the second (or even more) times it gets included, the preprocessor skips it.

Therefore, header files *always* must have include guards.

Do internal headers also need include guards? Well, no, because internal headers
are only ever going to be includes by the source files that implement the
functions in the header file. If programs or functions elsewhere need those
functions too, they should include the header file, not the internal header
file. Therefore, internal header files do not run the risk of being included
twice. So they need no header guards.

##### Summary

Eventually, the layout of the src/ directory is going to look like this:

    sudoku.cpp                   (including myfunctions/myfunctions.hh
                                  and perhaps misc/misc.hh)

    libproj.a                    (containing all objects from all subdirs)

    myfunctions/myfunctions.hh   (perhaps including misc.hh)
                myfunctions.ih   (including at least myfunction.hh)
                *.cpp            (all including only myfunctions.ih)

    misc/misc.hh
         misc.ih
         *.cpp

    more subdirs if needed

To build the project,
* all source files are compiled into objects,
* those objects that will not become programs go into the library,
* the other objects are linked against the library to become programs.

We will automate that process by using GNU Make and a convenient Makefile.
