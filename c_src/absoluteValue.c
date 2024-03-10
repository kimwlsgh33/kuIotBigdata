#include <stdio.h>
int main(void) {
  int num;
  printf("input num: ");
  scanf("%d", &num);
  /*
  if (num >= 0) {
    printf("absolute value : %d\n", num);
  } else {
    printf("absolute value : %d\n", -1 * num);
  }
  */
  printf("absolute value : %d\n", (num >= 0) ? num : -1 * num);
  return 0;
}
