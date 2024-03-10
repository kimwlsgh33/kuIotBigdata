#include <stdio.h>
int main(void) {
  // control variable
  // int ch = 'A';
  char ch = (int)'A'; // 65
  // 'A' ASCII code is a `integer` in C
  // so 'A' should be casted into char?

  // condition
  while (ch <= (int)'Z') { // 90
    // tasks
    printf("%c", (int)ch);
    ch++;
  }

  ch = 'a';           // 97
  while (ch <= 'z') { // 122
    printf("%c", ch);
    ch++;
  }

  printf("\n");

  // printf("ABCDEF....Z\n"); // This is better in the case
  return 0;
}
