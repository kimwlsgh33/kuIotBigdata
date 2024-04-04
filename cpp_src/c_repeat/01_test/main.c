#include <stdio.h>
int main(void) {
  char ch = 'A';
  char *chPtr = &ch;
  printf("chPtr : %p\n", chPtr);

  char fruit[20]; // address
  int cnt;        // value
  
  scanf("%d", &cnt);  // convert to address of value
  scanf("%s", fruit); // it is already address

  return 0;
}
