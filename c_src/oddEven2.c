#include <stdio.h>
int main(void) {
  int num;
  printf("input num: ");
  scanf("%d", &num);

  /* Comment */
  if (num % 2) {
    printf("%d is a odd\n", num);
  } else {
    printf("%d is a even\n", num);
  }
  return 0;
}
