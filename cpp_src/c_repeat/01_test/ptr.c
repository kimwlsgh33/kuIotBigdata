#include <stdio.h>

int main(void) {
  int a = 256;
  char *p = (char*)&a;
  printf("a : %d\n", a);
  printf("*p : %d\n", *p);
  return 0;
}
