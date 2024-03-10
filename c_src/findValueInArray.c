#include <stdio.h>
int main(void) {
  int nums[10] = {50, 90, 10, 20, 40, 80, 70, 100, 30, 60};

  int value;
  printf("input value : ");
  scanf("%d", &value);

  int i;
  // for (int i = 0; i < 10; ++i) {  // This will be not worked
  // because of the scope
  for (i = 0; i < 10; ++i) {
    if (value == nums[i]) {
      // found
      break; // switch-case, break the loop
    }        /* else {
             // not found
           } */
  }

  if (i != 10) {
    // found
    printf("%d is found. index : %d\n", value, i);
  } else {
    // not found
    printf("%d is not found\n", value);
  }

  return 0;
}
