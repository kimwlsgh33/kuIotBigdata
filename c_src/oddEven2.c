#include <stdio.h>
int main(void) {
  int num;
  printf("input num: ");
  scanf("%d", &num);

  /* Comment -- C */
  // Comment -- C++ (+1 : object oriented)
  // if (num % 2) {
  //   printf("%d is a odd\n", num);
  // } else {
  //   printf("%d is a even\n", num);
  // }

  printf("%d is a %s number\n", num, (num % 2 ) ? "odd" : "even");
  return 0;
}
