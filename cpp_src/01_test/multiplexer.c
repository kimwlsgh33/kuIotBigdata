#include <stdio.h>
int main(void) {
  // iterate 9 times
  for (int i = 1; i <= 9; ++i) {
    //==[oneline-start]=================================
    for (int j = 2; j <= 9; ++j) {
      printf("%d X %d = %d\t", j, i, j * i);
    }
    //==[oneline-end]=================================
    printf("\n");
  }

  return 0;
}
