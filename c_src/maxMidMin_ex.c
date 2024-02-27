#include <stdio.h>
int main(void) {
  int a, b, c;
  printf("input 3 numbers: ");
  scanf("%d %d %d", &a, &b, &c);

  int min, mid, max;

  // define 2 numbers first, and place a remainder
  if (a < b) {
    // a, b
    if (b < c) {
      // a, b, c
      min = a;
      mid = b;
      max = c;
    } else if (a < c) {
      // a, c, b
      min = a;
      mid = c;
      max = b;
    } else {
      // c, a, b
      min = c;
      mid = a;
      max = b;
    }
  } else {
    // b, a
    if (c > a) {
      // b, a, c
      min = b;
      mid = a;
      max = c;
    } else if (c > b) {
      // b, c, a
      min = b;
      mid = c;
      max = a;
    } else {
      // c, b, a
      min = c;
      mid = b;
      max = a;
    }
  }

  printf("max : %d\tmid : %d\tmin : %d\n", max, mid, min);
  return 0;
}
