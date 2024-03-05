#include <stdio.h>

void convertToLunar(int);

int main(void) {
  int year;

  printf("Enter a year in Gregorian calendar (AD): ");
  scanf("%d", &year);

  printf("Lunar year for %d AD:\n", year);
  convertToLunar(year);
  return 0;
}

void convertToLunar(int year) {
  int lunarYear = year + 9;
  printf("Lunar year: %d\n", lunarYear);
}
