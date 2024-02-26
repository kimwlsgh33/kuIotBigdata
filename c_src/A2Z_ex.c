#include <stdio.h>
int main(void){
  // int code;
  char code;
  printf("input character: ");
  // scanf("%d", &code);
  scanf("%c", &code);

  // int isBig = (code >= 65 && code <= 90);
  int isBig = (code >= 'A' && code <= 'Z');
  // %c : ASCII character
  printf("%c --- is big : %d\n", code, isBig);
  return 0;
}
