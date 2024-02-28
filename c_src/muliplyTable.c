#include <stdio.h>
int main(void) {
  for (int i = 2; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      // this scope is printed as a single line
      // multiply table of `2` is printed as a single line at first
      printf("%d X %d = %d\t", i, j, i * j);
    }
    // after printing a one line, moving to the next line
    printf("\n");
  }
  return 0;
}
