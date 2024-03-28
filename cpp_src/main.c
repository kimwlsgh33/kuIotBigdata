#include <stdio.h>

int main(void) {
  char name1[6] = {'T', 'r', 'a', 'c', 'e', '\0'};
  // char name1[5] = {'T', 'r', 'a', 'c', 'e'};
  char name2[5] = {'G', 'r', 'a', 'c', 'e'};

  printf("name1 : %s\n", name1);
  printf("name2 : %s\n", name2);
  printf("name1 : %p\n", name1);
  printf("name2 : %p\n", name2);
  return 0;
}
