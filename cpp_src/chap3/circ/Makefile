CC = g++
CFLAGS = -c
EXE = circle.out

SRCDIR = src
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(EXE) $(OBJDIR)/*.o

# main: main.o Circle.o 
# 	g++ main.o Circle.o -o main.out
#
# main.o: main.cpp
# 	g++ -c main.cpp
#
# Circle.o: Circle.cpp
# 	g++ -c Circle.cpp
