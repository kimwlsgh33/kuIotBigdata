#include <stdio.h>
// void swap(int a, int b) {
void swap(int *ap, int *bp) {
  // int tmp = a;
  // a = b;
  // b = tmp;
  int tmp = *ap;
  *ap = *bp;
  *bp = tmp;

  // return;
}

int main(void) {
  int a, b;
  a = 100;
  b = 200;
  printf("a: %d\tb: %d\n", a, b);

  // [swap]
  // you need a temporal variable to store data that is already stored
  // swap(a, b);
  swap(&a, &b);

  printf("a: %d\tb: %d\n", a, b);
  return 0;
}
