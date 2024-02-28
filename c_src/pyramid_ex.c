#include <stdio.h>
int main(void) {
  int num = 5;
  for (int i = 1; i <= num; ++i) {
    for (int j = 1; j <= num - i; ++j) {
      printf(" ");
    }
    for (int k = 1; k <= i * 2 - 1; ++k) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}

/**
 * 4 + 1
 * 3 + 3
 * 2 + 5
 * 1 + 7
 * 0 + 9
 */
