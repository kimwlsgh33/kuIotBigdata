#include <stdio.h>

int main(void)
{
  int fahr;

  fahr = 100;

  // multiply 1000 to fahr bc we want thousandths(place value)
  int celsius1000 = 1000 * 5 * (fahr - 32) / 9; //=> 37777

  int left = celsius1000 / 1000;
  // round => +5 => delete unit digit
  // 1) 37777 - 37000 => 777 => 777 + 5 => 782 => 
  // 2) 37777 % 1000 => 777 => 777 + 5 => 782 => 
  // 782 / 10 => 78 (the unit digit is deleted)
  // int right = (celsius1000 - celsius1000 / 1000 * 1000 + 5) / 10;
  int right = (celsius1000 % 1000 + 5) / 10;

  printf("fahr : %d ---> celsius : %d.%d\n", fahr, left, right);
  return 0;
}
