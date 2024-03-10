#include <stdio.h>

int main(void) {
  // output => 'A' : 1, 'a' : 0
  char ch;
  printf("input character: ");
  // `%c` character => ASCII code => int
  scanf("%c", &ch);

  // printf("Z : %d\n", 'Z'); // 'Z' : 90

  // int result = (65 <= ch) && (ch <= 96);
  // char + int = int
  int result = (65 <= ch) && (ch <= 90);

  printf("%c in [A,Z] : %d\n", ch, result);
  return 0;
}
