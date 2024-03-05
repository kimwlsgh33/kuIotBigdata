#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char my_string[1000];
  printf("input my_string : ");
  scanf("%s", my_string);

  char overwrite_string[1000];
  printf("input overwrite_string : ");
  scanf("%s", overwrite_string);

  int n;
  printf("input num : ");
  scanf("%d", &n);

  char *answer = malloc(1);
  return 0;
}
