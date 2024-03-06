#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
  int nums[6] = {0};
  // 주사위 개수 세기, 1 ~ 6
  srand(time(NULL));
  for (int i = 0; i < 100; ++i) {
    nums[i % 6] += 1;
  }
  printf("");
  return 0;
}
