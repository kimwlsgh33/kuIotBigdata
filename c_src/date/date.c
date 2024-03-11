#include "date.h"
#include <stdio.h>

int printDate1(Date d) {
  printf("(%d/%d/%d)\n", d.year, d.month, d.day);
  return 0;
}

// int printDate2(const struct date *pd) {
int printDate2(const Date *pd) {
  // printf("(%d/%d/%d)\n", d.year, d.month, d.day);
  // printf("(%d/%d/%d)\n", (*pd).year, (*pd).month, (*pd).day);
  // -> operator : access pointer's member
  printf("(%d/%d/%d)\n", pd->year, pd->month, pd->day);
  return 0;
}
