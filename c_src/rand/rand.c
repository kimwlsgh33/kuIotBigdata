// `global variable` can be accessed by ANY functions in ANY files
// int seed;

// `static variable` can be accessed by ANY functions in THIS file
static int seed;

// function definition - 정의
void my_srand(int s) {
  // seed = seed;
  seed = s;
}

int my_rand(void) {
  seed = seed * 1103515245 + 12345;
  return ((unsigned)(seed / 65536) % 32768);
}
