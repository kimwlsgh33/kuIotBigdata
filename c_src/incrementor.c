#include <stdio.h>

// operator precedence
int main(void) {
  int a, b;

  a = 1;
  b = ++a; // b : 2
  printf("++a: %d\tb: %d\n", a, b);

  a = 1;
  b = a++; // b : 1
  printf("a++: %d\tb: %d\n", a, b); 

  return 0;
}
