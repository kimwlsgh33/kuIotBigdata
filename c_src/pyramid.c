#include <stdio.h>
int main(void) {
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j < 6 - i; j++) {
      // first print 4, last print 1
      printf(" ");
    }
    for (int j = 1; j <= i * 2 - 1; j++) {
      // first print 1, last print 9
      printf("*");
    }
    printf("\n");
  }
  return 0;
}

/**
 * 4 + 1 + 4
 * 3 + 3 + 3
 * 2 + 5 + 2
 * 1 + 7 + 1
 * 0 + 9 + 0
 */
