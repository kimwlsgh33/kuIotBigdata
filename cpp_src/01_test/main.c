#include <stdio.h>
int main(void) {
  char ch = 'A';
  char *chPtr = &ch;
  printf("chPtr : %p\n", chPtr);
  return 0;
}
