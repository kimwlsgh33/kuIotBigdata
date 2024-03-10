#include <stdio.h>

// It would be better that use `max` variable than `pMax` pointer in terms of memory usage
int findMaxInArray(const int *pNums, int *pMax, int size) {
  *pMax = pNums[0];
  for (int i = 1; i < size; ++i) {
    if (*pMax < pNums[i]) {
      *pMax = pNums[i];
    }
  }
  
  return 0;
}

int main(void) {
  int nums[10] = {50, 90, 10, 20, 40, 80, 70, 100, 30, 60};
  int max;
  findMaxInArray(nums, &max, 10);

  printf("max: %d\n", max);

  return 0;
}
