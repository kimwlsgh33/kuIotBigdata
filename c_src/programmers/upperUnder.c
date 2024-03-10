#include <stdio.h>
#define LEN_INPUT 10

int main(void) {
  char s1[LEN_INPUT];
  int rs = scanf("%s", s1);
  // i : [0, 10)
  for (int i = 0; i < LEN_INPUT; ++i) {
    // if (s1[i] < 'A' || s1[i] > 'z')
    if (s1[i] == '\0')
      break;
    // If s1[i] is lowercase
    s1[i] = s1[i] > 'Z' ? s1[i] - 'a' + 'A' : s1[i] - 'A' + 'a';

    // printf("s1[%d] : %c\n", i, s1[i]);
  }
  printf("%s\n", s1);
  return 0;
}
