#!/usr/bin/make

# Simple Makefile. Source files either become programs, or they go into the
# convenience library, against which the programs are linked.

# https://www.gnu.org/software/make/manual/html_node/Reading-Makefiles.html

# If you want a new program name, change it here.
MAIN_PROG_SRC = sudoku.cpp

# If there are other than C++ programs, add them here.
PROGRAMS = $(CXX_PROGRAMS)

# How to add debug info.
#$(info PROGRAMS: $(PROGRAMS))

# If we forget (?=) to specify flags, use at least these.
CXXFLAGS ?= -Wall -std=c++2a

# We build a static convenience library. The linker needs flags to find them.
LDFLAGS += -L. -l$(LIBNAME)

# When compiling, generate dependency listings, too.
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.dep
DEPDIR = generated_deps

# Programs are main and whatever is in the 'programs' dir.
CXX_PROG_SOURCES = $(MAIN_PROG_SRC) $(wildcard programs/*.cpp)
CXX_PROGRAMS = $(patsubst %.cpp,%,$(CXX_PROG_SOURCES))

# We scan the entire directory for source files.
CXX_SOURCES = $(patsubst ./%,%,$(shell find ./ -type f -name \*.cpp))
CXX_OBJECTS = $(patsubst %.cpp,%.o,$(CXX_SOURCES))
CXX_OBJDEPS = $(patsubst %.cpp,%.dep,$(CXX_SOURCES))

# Whatever is not a program source goes into the library.
CXX_LIBSOURCES = $(filter-out $(CXX_PROG_SOURCES),$(CXX_SOURCES))
CXX_LIBOBJECTS = $(CXX_LIBSOURCES:.cpp=.o)

# Name of our library and the file containing it.
LIBNAME = proj
LIBRARY = lib$(LIBNAME).a

ENSURE_DIR = $(shell test -d $(dir $(DEPDIR)/$@) || mkdir -p $(dir $(DEPDIR)/$@))

# https://www.gnu.org/software/make/manual/html_node/Rules.html#Rules
# https://www.gnu.org/software/make/manual/html_node/Rule-Example.html#Rule-Example

# The default target (by convention called 'all') is: to build the programs.
all: $(PROGRAMS)

.PHONY: all

# Programs are built by linking their object files against the convenience
# library. This is a static pattern rule:
# https://www.gnu.org/software/make/manual/html_node/Static-Usage.html#Static-Usage
# We don't call the linker directly. We call it through the compiler.
$(CXX_PROGRAMS): %: %.o $(LIBRARY)
	@printf "[Linking $@]\n\t"
	$(ENSURE_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

# The library contains all object files that don't become programs.
$(LIBRARY): $(CXX_LIBOBJECTS)
	@printf "[Composing $@]\n\t"
	ar rcs $@ $^

# Any non-program C++ source builds an object that goes into the library.
# The use of $(DEPFLAGS) causes a dependency file to also be written.
# (But Make does not know that!)
$(CXX_OBJECTS): %.o: %.cpp | $(DEPDIR)
	@printf "[Compiling $@]\n\t"
	$(ENSURE_DIR)
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

# Source files need to be recompiled when header files that they include are
# newer than the object. Including the generated dependency files ensures this.
# If make has run previously, $(DEPDIR) will exist.
ifneq (,$(wildcard $(DEPDIR)))

    # In that case, find all .dep-files in $(DEPDIR) and include them.
    FOUND_CXX_DEPS = $(shell find $(DEPDIR) -name \*.dep)

    # They list the dependencies of source files on the headers they include,
    # which ensures that sources that include foo.hh have their objects rebuilt
    # when foo.hh is newer. Thus we need run 'make clean' less often.
    -include $(FOUND_CXX_DEPS)

    # Don't let Make try to rebuild the .deps. (We don't even tell it how to,
    # but it will try to find a rule for them anyway.)
    $(FOUND_CXX_DEPS):;
endif

# Also block any attempts to remake the Makefile itself.
Makefile:;

# https://www.gnu.org/software/make/manual/html_node/index.html
