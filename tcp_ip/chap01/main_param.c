#include <stdio.h>
#include <stdlib.h>

// argc: count of argment
int main(int argc, char *argv[]) {
  printf("argc : %d\n", argc);

  int sum = 0;
  // printf("argv[%d] : %s\n", 0, argv[0]);
  for (int i = 1; i < argc; ++i) {
    // printf("argv[%d] : %s\n", i, argv[i]);
    sum += atoi(argv[i]);
  }

  for (int i = 1; i < argc - 1; ++i) {
    printf("%s + ", argv[i]);
  }
  printf("%s ", argv[argc - 1]);
  printf("= %d\n", sum);

  return 0;
}
