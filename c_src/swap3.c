#include <stdio.h>
// global variable : lifetime is as long as the program
// don't use as long as possible
int a, b;
// int tmp;

// void swap(int a, int b) {
void swap() {
  // tmp = a;
  // local variable : lifetime is as long as the swap function
  int tmp = a;
  a = b;
  b = tmp;
}

int main(void) {
  // int a, b;
  a = 100;
  b = 200;
  printf("a: %d\tb: %d\n", a, b);

  // swap(a, b);
  swap();
  // Pros : This is reduce overhead
  // Cons : spagetti code

  printf("a: %d\tb: %d\n", a, b);

  return 0;
}
