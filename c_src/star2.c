#include <stdio.h>

int main(void) {
  for (int i = 1; i <= 5; i++) {
    // How many times should we loop?
    for (int j = 1; j <= i * 2 - 1; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
