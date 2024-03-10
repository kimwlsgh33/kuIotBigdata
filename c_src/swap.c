#include <stdio.h>
int main(void) {
  int a, b;
  a = 100;
  b = 200;

  printf("a: %d\tb: %d\n", a, b);
  
  // swap - you need empty space to swap them!
  int tmp = a;
  a = b; // a : 200, b : 200
  // b = a; 
  b = tmp; 

  printf("a: %d\tb: %d\n", a, b);
  
  return 0;
}
