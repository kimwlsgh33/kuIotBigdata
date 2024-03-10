#include <stdio.h>
int main(void) {
  // i: 1 ~ 5
  for (int i = 1; i <= 5; i++) {

  // j: 1 ~ 5
    for (int j = 1; j <= 5; j++) {
      if (j == i || j + i == 6){
        printf("x");
      } else {
        printf("o");
      }
    }
    printf("\n");

  }
  return 0;
}

/*
* xooox
* oxoxo
* ooxoo
* oxoxo
* xooox
*
* 1) xooox -> i: 1, j: 1 ~ 5 -> j: 1, j: 5 -> i == j, (1,5) i + j == 6
*
* 2) oxoxo -> i: 2, j: 1 ~ 5 -> j: 2, j: 4 -> i == j, (2,4)
*
* 3) ooxoo -> i: 3, j: 1 ~ 5 -> j: 3, j: 3 -> i == j, (3,3)
*
* 4) oxoxo -> i: 4, j: 1 ~ 5 -> j: 4, j: 2 -> i == j, (4,2)
*
* 5) oxoxo -> i: 5, j: 1 ~ 5 -> j: 5, j: 1 -> i == j, (5,1)
*/
