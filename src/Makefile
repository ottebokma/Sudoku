#!/usr/bin/make

# If there are other than C++ programs, add them here.
PROGRAMS = $(CXX_PROGRAMS)

# If we forget (?=) to specify flags, we want to use these.
CXXFLAGS ?= -Wall -std=c++2a

# Find and use the convenience library.
LDFLAGS += -L. -l$(LIBNAME)

# Programs are sudoku and whatever is in the 'programs' dir.
CXX_PROG_SOURCES = sudoku.cpp $(wildcard programs/*.cpp)
CXX_PROGRAMS = $(patsubst %.cpp,%,$(CXX_PROG_SOURCES))

# We scan the entire directory for source files.
CXX_SOURCES = $(patsubst ./%,%,$(shell find ./ -type f -name \*.cpp))
CXX_OBJECTS = $(patsubst %.cpp,%.o,$(CXX_SOURCES))

# Whatever is not a program source goes into the library.
CXX_LIBSOURCES = $(filter-out $(CXX_PROG_SOURCES),$(CXX_SOURCES))
CXX_LIBOBJECTS = $(patsubst %.cpp,%.o,$(CXX_LIBSOURCES))

# Name of library and the file continaing it.
LIBNAME = proj
LIBRARY = lib$(LIBNAME).a

# How to add debug info.
#$(info PROGRAMS: $(PROGRAMS))

# The default target (by convention called 'all') is: to build the programs.
all: $(PROGRAMS)

# Programs are built by linking their object files against the convenience library.
$(CXX_PROGRAMS): %: %.o $(LIBRARY)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $<

# The library contains all other objects.
$(LIBRARY): $(CXX_LIBOBJECTS)
	ar rcs $@ $^

# Any non-program C++ source builds an object that goes into the library.
# This is a static pattern rule: ( https://www.gnu.org/software/make/manual/html_node/Static-Usage.html#Static-Usage )
# It says that for each of $(PROGRAMS), we can build X if we have X.cpp,
# *and* it says that if X.cpp is newer than X, X needs to be rebuilt.
# The recipe calls CXX with al appropriate flags, with the target as output and the first prerequisite as input.
$(CXX_OBJECTS): %.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

# 'make clean' removes all generated files.
clean:
	rm -f $(PROGRAMS) $(CXX_OBJECTS) $(LIBRARY)

# Even if a file 'clean' should exist, run the recipe anyway.
.PHONY: clean

# Block any attempts to remake the Makefile.
Makefile:;
