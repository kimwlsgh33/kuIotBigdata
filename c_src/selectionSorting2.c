#include <stdio.h>

void sorting(int *pArr, int size) {
  // i : [0, size - 1)
  for (int i = 0; i < size - 1; ++i) {
    // j : [i + 1, size)
    for (int j = i + 1; j < size; ++j) {
      if (pArr[i] > pArr[j]) {
        int tmp = pArr[i];
        pArr[i] = pArr[j];
        pArr[j] = tmp;
      }
    }
  }
}

int main(void) {
  int nums[10] = {50, 90, 10, 20, 40, 80, 70, 100, 30, 60};

  // selection sorting
  sorting(nums, 10);

  // you need to write outputs first.
  for (int i = 0; i < 10; ++i) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}
