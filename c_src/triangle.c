#include <stdio.h>

int main(void) {
  int width, height;
  // int height;

  printf("input width : ");
  scanf("%d", &width);

  printf("input height : ");
  scanf("%d", &height);

  printf("area : %.1f\n", width * height / 2.0);

  return 0;
}
