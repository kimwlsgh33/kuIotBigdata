#include <stdio.h>
int main(void) {
  int nums[10] = {50, 90, 10, 20, 40, 80, 70, 100, 30, 60};

  int sum; // declaration
  sum = 0; // assignment

  for (int i = 0; i < 10; ++i) {
    sum = sum + nums[i]; // accumulate : sum += nums[i];
  }

  printf("sum: %d\n", sum);

  return 0;
}
