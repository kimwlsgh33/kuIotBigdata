#include <stdio.h>
int main(void) {
  // define variable == create memory(RAM) space

  /*
  int i;
  i = 1;
  while (i <= 10) {
    printf("i : %d\n", i);
    i++;
  }
  */

  //
  int a = 1;
  int b = a++; // b -> sol : 2, hae : 1, jin : 1

  a = 1;
  b = ++a; // sol : 1, hae : 2, jin : 2
  //

  // for (int i = 1; i <= 10; ++i) {
  for (int i = 1; i <= 10; i++) {
    printf("i : %d\n", i);
  }

  return 0;
}
