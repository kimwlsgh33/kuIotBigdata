#include <stdio.h>

int main(void) {
  // loop 5 times
  for (int i = 1; i <= 5; i++) {
    // for (int j = 1; j <= i; j++) {
    // for (int j = 1; j <= i * 2 - 1; j++) {
    for (int j = 1; j <= 6 - i; j++) {
      printf("*");
    }
    printf("\n");
  }

  // reverse the `i`
  for (int i = 5; i >= 1; i--) {
    // first `i` == 5
    for (int j = 1; j <= i ; j++) {
      // first print == "*****"
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
