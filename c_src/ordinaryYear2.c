#include <stdio.h>
int main(void) {
  int year;
  printf("input year: ");
  scanf("%d", &year);

  if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0) {
    printf("%d is a ordinary year\n", year);
  } else {
    printf("%d is not a ordinary year\n", year);
  }
  return 0;
}
