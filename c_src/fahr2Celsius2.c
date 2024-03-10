#include <stdio.h>

int main(void)
{
  int fahr;
  // double : double floating point
  double celsius;

  fahr = 100;
  celsius = 5.0 / 9.0 * (fahr - 32);

  // .2 : right side of a number of the floating number
  printf("fahr : %d ---> celsius: %.2f\n", fahr, celsius);

  return 0;
}
