#include "myString.h"
#include <stdio.h>
// #include <string.h>

int main(void) {
  char buf1[100];
  char buf2[100];

  printf("Hello, World!");
  // strcat(buf1, "abc");
  my_strcat(buf1, "abc");
  printf("%s\n", buf1);
  // strcat(buf1, "def");
  my_strcat(buf1, "def");
  printf("%s\n", buf1);
  // printf("%s\n", strcat(buf1, "ghi"));
  // printf("%s\n", my_strcat(buf1, "ghi"));
  my_strcat(buf1, "ghi");
  // printf("%d\n", strcmp("abcde", "abcfe")); // eq: 0, ne: -1
  printf("%d\n", my_strcmp("abcde", "abcfe")); // eq: 0, ne: -1
  // strcpy(buf2, buf1);
  my_strcpy(buf2, buf1);
  // if (strcmp(buf1, buf2) == 0) {
  if (my_strcmp(buf1, buf2) == 0) {
    printf("두 스트림 변수는 같다.\n");
  } else {
    printf("두 스트림 변수는 다르다.\n");
  }
  // printf("%d\n", (int)strlen(buf1));
  printf("%d\n", (int)my_strlen(buf1));
  // printf("%ld\n", strlen(buf2));
  printf("%d\n", my_strlen(buf2));
  // strcat(buf1, buf2);
  my_strcat(buf1, buf2);
  // printf("%ld\n", strlen(buf1));
  printf("%d\n", my_strlen(buf1));

  return 0;
}
