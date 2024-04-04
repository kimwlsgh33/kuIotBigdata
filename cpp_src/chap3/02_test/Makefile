CC = g++
EXE = main.out
CFLAGS = -c

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

%.o: %.c
	$(CC) -std=c++11 $(CFLAGS) $<

clean:
	rm -f *.o *.out
