#include <stdio.h>

void printStringArray1(char (*str)[21], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%s\n", &str[i][0]); // &str[i][0] == str[i]
  }
}

void printStringArray2(char *str[], int size) {
  // void printStringArray2(char **str, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%s\n", str[i]); // &str[i] = str[i][0]
  }
}

int main(void) {
  // const char *str = "hello world";
  char cities1[][21] = {"Seoul", "Los Angeles", "Rio de janeiro", "Moscow",
                        "Paris"};

  printStringArray1(cities1, 5); // &cities1[0] : char *[]

  char *cities2[] = {"Seoul", "Los Angeles", "Rio de janeiro", "Moscow",
                     "Paris"};

  printStringArray2(cities2, 5); // &cities2[0] : char *
  return 0;
}
