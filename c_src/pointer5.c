#include <stdio.h>

int add(int a, int b) { return a + b; }

int substract(int a, int b) { return a - b; }

int main(void) {
  int a = 4;
  int b = 3;

  int (*fp)(int, int); // function pointer

  fp = &add;
  int re = (*fp)(a, b); // add(a, b)
  printf("re: %d\n", re);

  // function names are a address
  // fp = &substract;
  fp = substract;
  // re = (*fp)(a, b); // substract(a, b)
  re = fp(a, b);
  printf("re: %d\n", re);

  return 0;
}
