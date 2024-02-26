#include <stdio.h>
int main(void) {
  // 2024 : 1, 2023 : 0
  // unsigned short year; // 65536
  int year;
  printf("input year: ");
  scanf("%d", &year);
  char isLeap = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
  // char isLeap = (year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0) ;

  printf("%d is a leap : %d\n", year, isLeap);

  // short-cut circuit
  // 0 && x => 확률이 낮은 것을 앞에
  // 1 || y => 확률이 높은 것을 앞에

  return 0;
}
