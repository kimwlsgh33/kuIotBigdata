#include <stdio.h>

int sumArray(int *pNums, int *pSum, int size) {
  *pSum = 0;
  for (int i = 0; i < size; ++i) {
    *pSum += pNums[i]; // *(pNums + i) : a value of the next element
  }

  return 0;
}

int main(void) {
  int nums[10] = {50, 90, 10, 20, 40, 80, 70, 100, 30, 60};

  int sum; // declaration
  sumArray(nums, &sum, 10);

  printf("sum: %d\n", sum);

  return 0;
}
