#include <stdio.h>
int main(void){
  char code;
  printf("input ASCII: ");
  scanf("%c", &code);
  // int isAlpha = (code >= 65 && code <= 90) || (code >= 97 && code <= 122);
  int isAlpha = (code >= 'A' && code <= 'Z') || (code >= 'a' && code <= 'z');
  printf("%c is alpha : %d\n", code, isAlpha);
  return 0;
}

int test(void){
  return 0;
}
