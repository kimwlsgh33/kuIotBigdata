#include <stdio.h>
int main(void) {
  // 2024 : 1, 2023 : 0
  // unsigned short year; // 65536
  int year;
  printf("input year: ");
  scanf("%d", &year);
  char isOrdinary;
  isOrdinary = !((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
  // Logical product
  isOrdinary = (year % 4 != 0) || (year % 100 == 0) && (year % 400 != 0);

  printf("%d is a ordinary : %d\n", year, isOrdinary);

  // short-cut circuit
  // 0 && x => 확률이 낮은 것을 앞에
  // 1 || y => 확률이 높은 것을 앞에

  return 0;
}
