#include <stdio.h>
int main(void) {
  int a;
  int *p; // make a pointer

  a = 100;
  p = &a; // store address of `a` into `p`
  *p = 200; // dereferencing `p` so it trasforms into a

  printf("%d\n", a);
  return 0;
}
