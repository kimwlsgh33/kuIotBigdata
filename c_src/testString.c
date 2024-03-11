#include <stdio.h>
#include <string.h>

int main(void) {
  char *str1 = "hello, world";
  // '\0' is not included!
  int len = strlen(str1);

  printf("len : %d\n", len);

  char str2[13];
  // char *str2; // segmentation error
  // char str2[12]; // out of bound - buffer overflow - c doesn't check the length
  // 12 normal code + hacking code => jump to hacking code

  // (dest, src)
  strcpy(str2, str1);

  printf("str2 : %s\n", str2);

  if (strcmp(str1, str2) == 0) {
    printf("str1 and str2 are equal\n");
  } else {
    printf("str1 and str2 are not equal\n");
  }

  // string functions are many, you need to see these

  return 0;
}
