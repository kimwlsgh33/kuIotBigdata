#include <stdio.h>
int main(void) {
  int a, b, c;
  printf("input 3 numbers: ");
  scanf("%d %d %d", &a, &b, &c);

  int min, mid, max;

  // insert two numbers with order first
  if (a > b) {
    min = b;
    max = a;
  } else {
    min = a;
    max = b;
  }

  // leverage the previous order
  if (c > max) {
    mid = max;
    max = c;
  } else if (c > min) {
    mid = c;
  } else {
    mid = min;
    min = c;
  }

  printf("max : %d\tmid : %d\tmin : %d\n", max, mid, min);
  return 0;
}
