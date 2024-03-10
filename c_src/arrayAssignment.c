#include <stdio.h>

int main(void) {
  int nums1[5] = {1, 2, 3, 4, 5};
  int nums2[5] = {0};

  // nums = results; // This is not possible

  for (int i = 0; i < 5; ++i) {
    nums2[i] = nums1[i];
  }

  printf("nums1\n");
  for (int i = 0; i < 5; ++i) {
    printf("%d ", nums1[i]);
  }
  printf("\n");
  
  printf("nums2\n");
  for (int i = 0; i < 5; ++i) {
    printf("%d ", nums2[i]);
  }
  printf("\n");
  
  return 0;
}
