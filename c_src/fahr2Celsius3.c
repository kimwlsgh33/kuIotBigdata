/* output:
 * fahr : 100 ---> celsius : 37.78
 *
 * requirements:
 * no floating points (5.0, 9.0, %f, etc.)
 */
#include <stdio.h>

int main(void) {
  int fahr;
  int left;  // quotient
  int right; // remainder
  int round;

  fahr = 100;

  left = 5 * (fahr - 32) / 9;
  // 9 + 5 ??? => round
  // right0, right1
  right = 5 * (fahr - 32) * 100 / 9 - left * 100;
  round = ((5 * (fahr - 32) * 1000 / 9 - left * 1000) -
           (5 * (fahr - 32) * 100 / 9 - left * 100) * 10) /
          5;

  // 37.78
  printf("fahr : %d ---> celsius : %d.%d\n", fahr, left,
         right + round);
  return 0;
}
