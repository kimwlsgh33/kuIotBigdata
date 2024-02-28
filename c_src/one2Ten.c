#include <stdio.h>
int main(void) {
  int i;

  i = 1;
  while (i <= 10) {
    printf("i : %d\n", i);
    i++;
  }
  
  // if i < 1000? -> a code size is increased (storage usage)
  // printf("i : 1\n");
  // printf("i : 2\n");
  // printf("i : 3\n");
  // ...
  
  return 0;
}
