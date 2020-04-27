#!/usr/bin/make

# If there are other than C++ programs, add them here.
PROGRAMS = $(CXX_PROGRAMS)

# If we forget (?=) to specify flags, we want to use these.
CXXFLAGS ?= -Wall -std=c++2a

# Find and use the convenience library.
LDFLAGS += -L. -l$(LIBNAME)

# When compiling, generate dependency listings, too.
DEPDIR = generated_deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.dep

# Programs are 'sudoku' and whatever is in the 'programs' dir.
CXX_PROG_SOURCES = sudoku.cpp $(wildcard programs/*.cpp)
CXX_PROGRAMS = $(patsubst %.cpp,%,$(CXX_PROG_SOURCES))

# We scan the entire directory for source files.
CXX_SOURCES = $(patsubst ./%,%,$(shell find ./ -type f -name \*.cpp))
CXX_OBJECTS = $(patsubst %.cpp,%.o,$(CXX_SOURCES))
CXX_OBJDEPS = $(patsubst %.cpp,%.dep,$(CXX_SOURCES))

# Whatever is not a program source goes into the library.
CXX_LIBSOURCES = $(filter-out $(CXX_PROG_SOURCES),$(CXX_SOURCES))

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
$(CXX_OBJECTS): %.o: %.cpp $(DEPDIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPFLAGS) -c -o $@ $<

# This is where we store the dependencies.
$(DEPDIR):
	mkdir $@

# 'make clean' removes all generated files.
clean:
	rm -f $(PROGRAMS) $(CXX_OBJECTS) $(LIBRARY)
	rm -rf $(DEPDIR)

# Even if a file 'clean' should exist, run the recipe anyway.
.PHONY: clean

# Block any attempts to remake the Makefile.
Makefile:;

# Source files need to be recompiled when header files that they include are
# newer than the object. Including the generated dependency files ensures this.
ifneq (,$(wildcard $(DEPDIR)))
    -include $(shell find $(DEPDIR) -name \*.dep)
endif
