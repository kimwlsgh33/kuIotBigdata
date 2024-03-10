#include <stdio.h>
int main(void) {
  // i: 0 ~ 4
  for (int i = 0; i < 5; i++) {

    // 0 ~ 4
    // for (int x = 0; x < 5; x++) {
    //   // first 1ooo5
    //   if (i + x % 2) {
    //     printf(" ");
    //   } else {
    //     printf("*");
    //   }
    // }

    // 4 ~ 0
    // for (int y = 4; y >= 0; y--) {
    //   // first 1ooo5
    //   if (i + y % 2) {
    //     printf(" ");
    //   } else {
    //     printf("*");
    //   }
    // }

    // x: 0 ~ 4, y: 4 ~ 0
    for (int x = 0, y = 4; x < 5; x++, y--) {
      // i:0, i+x:0, i+y:4 X (i+y)
      // i:0, i+x:1, i+y:3
      // i:0, i+x:2, i+y:2
      // i:0, i+x:3, i+y:1
      // i:0, i+x:4, i+y:0 X (i+x)
      //
      // i:1, i+x:1, i+y:5 
      // i:1, i+x:2, i+y:4 X (i+y)
      // i:1, i+x:3, i+y:3
      // i:1, i+x:4, i+y:2 X (i+x)
      // i:1, i+x:5, i+y:1
      //
      // i:2, i+x:2, i+y:6 
      // i:2, i+x:3, i+y:5 
      // i:2, i+x:4, i+y:4 X (i+x), (i+y)
      // i:2, i+x:5, i+y:3
      // i:2, i+x:6, i+y:2
      //
      // i:3, i+x:3, i+y:7 
      // i:3, i+x:4, i+y:6 X (i+x)
      // i:3, i+x:5, i+y:5 
      // i:3, i+x:6, i+y:4 X (i+y)
      // i:3, i+x:7, i+y:3
      //
      // i:4, i+x:4, i+y:8 X (i+x), (i+y)
      // i:4, i+x:5, i+y:7 
      // i:4, i+x:6, i+y:6 
      // i:4, i+x:7, i+y:5 
      // i:4, i+x:8, i+y:4 X (i+x), (i+y)
      if ((i + x) % 4 == 0 || (i + y) % 4 == 0) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}

/*
 * xooox  1   5  (0,0),(0,4)
 *
 * oxoxo   2 4   (1,1),(1,3)
 *
 * ooxoo    3    (2,2),(2,2)
 *
 * oxoxo   2 4   (3,1),(3,3)
 *
 * xooox  1   5  (4,0),(4,4)
 *
 * (i, x), (i, y) => (i + x) % 2 == (i + y) % 2 == 0
 */
