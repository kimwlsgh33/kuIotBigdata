#include <stdio.h>
int main(void) {
  /*
  char ch = 'A';
  while (ch <= 'Z') {
    printf("%c\n", ch);
    ch++;
  }
  */

  for (char ch = 'A'; ch <= 'Z'; ch++) {
    printf("%c", ch);
  }
  printf("\n");

  return 0;
}
