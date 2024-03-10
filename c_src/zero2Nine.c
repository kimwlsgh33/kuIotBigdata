#include <stdio.h>

int main(void) {
  int num;
  printf("input num: ");
  scanf("%d", &num);

  // int result = (0 <= num <= 9);
  int result = (0 <= num) && (num <= 9);

  // printf("between 0 and 9 : %d\n", result);
  printf("[0, 9] : %d\n", result);

  // [] : opened range
  // () : closed range

  return 0;
}
