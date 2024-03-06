// This file cannot be compiled by zig compiler
#include <stdio.h>
// #include <stdlib.h>
#include <time.h>

// This can be accessed by ANY functions in ANY files
int seed;

// void srand(int seed) {
void my_srand(int s) {
  // seed = seed;
  seed = s;
}

int my_rand(void) {
  seed = seed * 1103515245 + 12345;
  return ((unsigned)(seed / 65536) % 32768);
}

int main(void) {
  /*
  int seed;
  srand(time(NULL), &seed);
  seed = 0;
  int value = rand(&seed);
  */

  // srand(time(NULL));
  my_srand(time(NULL));

  for (int i = 0; i < 10; ++i) {
    // int value = rand();
    int value = my_rand();

    printf("value : %d\n", value);
  }

  return 0;
}
