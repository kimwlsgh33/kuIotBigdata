#include <stdio.h>
int main(void) {
  int nums[5] = {1, 2, 3, 4, 5};
  int *p;
  
  p = nums; // return value : &nums[0]

  printf("*p : %d\n", *p); // *&nums[0] -> nums[0]
  ++p;
  printf("*p : %d\n", *p); // *&nums[1] -> nums[1]
  
  p = nums;

  printf("*(p + 2) : %d\n", *(p + 2)); // *&nums[2] -> nums[2]
    
  return 0;
}
