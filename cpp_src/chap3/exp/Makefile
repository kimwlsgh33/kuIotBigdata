CC = g++
EXE = main.out
CFLAGS = -c

SRCS = $(wildcard ./*.cpp)
OBJS = $(patsubst ./%.cpp, ./%.o, $(SRCS))

# file : requirements
$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

# $< : first requirment
%.o: %.cpp
	$(CC) -std=c++11 $(CFLAGS) $<

clean:
	rm -f *.o *.out
