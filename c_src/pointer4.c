#include <stdio.h>
int main(void) {
  int a;
  int *pa;
  int **ppa;

  a = 100;
  pa = &a; // unit pointer
  ppa = &pa; // muti pointer

  **ppa = 200;

  printf("a : %d\n", a);
}
