#include <stdio.h>
int main(void) {
  // 1. why should we use i, j, k? => history of high level language => FORTRAN
  // => i, j, k, l, m, n (integer), u, v, w, x, y, z (floating point)
  // 2. why should we use `++i` rather than `i++`?
  // => `i++` need a temporal variable
  // 1 ~ 5
  for (int i = 1; i <= 5; ++i) {
    // 1 ~ 5
    for (int j = 1; j <= 5; ++j) {
      if (i == j || i + j == 6) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
// 1. i == j  -> *
// 2. i + j == 6  -> *

/*
 * xooox  1   5   i : 1, j : 1 ~ 5    -> (j: 1), j: 5  => *  i : 1, j : 5
 *
 * oxoxo   2 4    i : 2, j : 1 ~ 5    -> (j: 2), j: 4  => *  i : 2, j : 4
 *
 * ooxoo    3     i : 3, j : 1 ~ 5    -> (j: 3), j: 3  => *  i : 3, j : 3
 *
 * oxoxo   2 4    i : 4, j : 1 ~ 5    -> j: 2, (j: 4)  => *  i : 4, j : 2
 *
 * xooox  1   5   i : 5, j : 1 ~ 5    -> j: 1, (j: 5)  => *  i : 5, j : 1
 *
 * (i, x), (i, y) => (i + x) % 2 == (i + y) % 2 == 0
 */
