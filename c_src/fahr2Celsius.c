#include <stdio.h>

int main(void)
{
  // print only integer
  int fahr;
  int celsius;

  fahr = 100;
  // *********** My Wrong ***************
  // 5(int) / 9(int) => 0.555 => 0(int)...
  // celsius = 5 / 9 * (fahr - 32);
  celsius = 5.0 / 9.0 * (fahr - 32); // return value is truncated
  // ************************************

  // %d : integer format specifier
  printf("fahr : %d ---> celsius : %d\n", fahr, celsius);

  return 0;
}
