#include <stdio.h>
int main(void) {
  int a, b, c;
  printf("input 3 numbers: ");
  scanf("%d %d %d", &a, &b, &c);

  int min, mid, max;

  if (a > b) {
    if (a > c) {
      // a > b && a > c
      max = a;
      if (b > c) {
        // a > b && a > c && b > c
        mid = b;
        min = c;
      } else {
        // a > b && a > c && b < c
        mid = c;
        min = b;
      }
    } else {
      // b < a && a < c
      min = b;
      mid = a;
      max = c;
    }
  } else if (a < c) {
    // a < b && a < c
    min = a;
    if (b > c) {
      // a < b && a < c && b > c
      mid = c;
      max = b;
    } else {
      // a < b && a < c && b < c
      mid = b;
      max = c;
    }
  } else {
    // b < a && a < c
    min = b;
    mid = a;
    max = c;
  }

  printf("max : %d\tmid : %d\tmin : %d\n", max, mid, min);
  return 0;
}
