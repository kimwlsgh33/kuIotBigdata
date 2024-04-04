#include <stdio.h>
int main(void) {
  int sum = 0;
  int start = 1, end = 100;
  int mul1 = 3, mul2 = 7;

  for (int i = start; i <= end; ++i) {
    if (i % (mul1 * mul2) == 0) {
      // if (i % mul1 == 0 || i % mul2 == 0) {
      // continue;
      sum += i;
    }
    // sum += i;
  }

  printf("%d ~ %d중, %d의배수 값들의 총합 : %d\n", start, end, mul1 * mul2,
         sum);

  return 0;
}
