#include <stdio.h>
#define LEN_INPUT 10

int main(void) {
  char s1[LEN_INPUT];
  scanf("%s", s1);
  char *cp = s1 - 1;
  // This should be stop if cp's value is 0
  while (*++cp)
    printf("%c\n", *cp);

  // arithmatic operations on pointer depends on
  // the size of a pointed value type
  // ++cp => ++char because cp's value type is char

  return 0;
}
