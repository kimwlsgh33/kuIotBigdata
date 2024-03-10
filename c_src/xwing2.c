#include <stdio.h>
int main(void) {
  // i: 0 ~ 4
  for (int i = 0; i <= 4; i++) {
    // j: 0 ~ 4, 4 - i: 4 ~ 0
    for (int j = 0; j <= 4; j++) {
      if ((i + j) % 4 == 0 || (i + 4 - j) % 4 == 0) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
