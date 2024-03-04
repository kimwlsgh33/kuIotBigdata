#include <stdio.h>
int main(void) {
  int nums[10] = {50, 90, 10, 20, 40, 80, 70, 100, 30, 60};

  // bubble sorting - the maximum is a bubble
  // max : 9 -> 1, 0 is setted automatically
  for (int i = 9; i >= 1; --i) {
    // j : 0 ~ maximum of i - 1 : 0 ~ 9 - 1 : 0 ~ 8
    for (int j = 0; j < i; ++j) {
      // j : prev, j + 1 : next
      // > : asd
      if (nums[j] > nums[j + 1]) {
        // swap
        int tmp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = tmp;
      }
    }
  }

  for (int i = 0; i < 10; ++i) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  return 0;
}
