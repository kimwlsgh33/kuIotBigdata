#include <stdio.h>

// There are no changes to the target
int findMaxInArray(const int *pArr, int size) {
  int max = pArr[0];
  for (int i = 1; i < size; ++i) {
    if (max < pArr[i]) {
      max = pArr[i];
    }
  }
  return max;
}

int main(void) {
  int nums[10] = {50, 90, 10, 20, 40, 80, 70, 100, 30, 60};

  int max;
  max = findMaxInArray(nums, 10);

  printf("max: %d\n", max);

  return 0;
}
