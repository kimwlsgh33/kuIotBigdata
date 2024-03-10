# Compiling a C program: `n.o` is made automatically from `n.c` with a command of the form:
# `$(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -o $@`

# Compiling a C++ program: `n.o` is made automatically from `n.cc` or `n.cpp` with a command of the form:
# `$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $^ -o $@`

# Liking a single object file: `n` is made automatically from `n.o` by running the command:
# `$(CC) $(LDFLAGS) $^ $(LOADLIBS) $(LDLIBS) -o $@`

# The important variables used by implicit rules are:
# CC : Program for compiling C programs; default `cc`
# CXX : Program for compiling C++ programs; default `g++`
# CFLAGS : Extra flags to give to the C compiler
# CXXFLAGS: Extra flags to give to the C++ compiler
# CPPFLAGS: Extra flags to give to the C preprocessor
# LDFLAGS : Extra flags to give to compilers when they are supposed to invoke the linker
# LDLIBS : Extra libraries to link against
# LOADLIBS: Extra libraries to link against
# LDLIBS : Extra libraries to link against

CC = gcc # Flag for implicit rules
CFLAGS = -g # Flags for implicit rules. Turn on debug info

# Implicit rule #1: blah is built via the C linker implicit rule
# Implicit rule #2: blah.o is built via the C compilation implicit rule, because blah.c exists
blah: blah.o

blah.c:
	echo "int main() { return 0; }" > blah.c

clean:
	rm -f blah*
