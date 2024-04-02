CC = g++
CFLAGS = -c
EXE = calc.out

SRCDIR = src
OBJDIR = obj

# catch all sources
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# convert `*.c` into `*.o` (pattern, replacement, text)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# create executable
$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

# create object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(EXE) $(OBJDIR)/*.o
