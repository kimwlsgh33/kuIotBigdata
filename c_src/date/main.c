#include "date.h"

int main(void) {
  // struct date today;
  Date today;
  today.year = 2024;
  today.month = 3;
  today.day = 11;

  // struct date birthday = {2005, 8, 2};
  Date birthday = {2005, 8, 2};

  printDate1(today);
  printDate1(birthday);
  
  printDate2(&today);
  printDate2(&birthday);

  return 0;
}
