#include <stdio.h>
int main(void) {
  int nums[10] = {50, 90, 10, 20, 40, 80, 70, 100, 30, 60};

  // selection sorting
  // nums[0] = min value of array
  // 0 => 1, 2, 3, 4, 5, 6, 7, 8, 9
  // nums[1] = min value of remained array
  // 1 => 2, 3, 4, 5, 6, 7, 8, 9
  // nums[7]
  // 7 => 8, 9
  // nums[8]
  // 8 => 9 (you don't need to check the condition)
  
  // i : prev (0 ~ 9)
  for (int i = 0; i < 10; ++i) {
    // j : next (i + 1 ~ 9)
    for (int j = i + 1; j < 10; ++j) {
      // > : asd
      if (nums[i] > nums[j]) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
      }
    }
  }
  
  // you need to write outputs first.
  for (int i = 0; i < 10; ++i){
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}
