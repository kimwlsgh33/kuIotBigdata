#include <stdio.h>
int main(void) {
  char ch;
  printf("input a letter: ");
  scanf("%c", &ch);

  // if (ch >= 'A' && ch <= 'Z')
  if (ch >= 65 && ch <= 90) {
    printf("%c is a uppercase\n", ch);
  }
  return 0;
}
