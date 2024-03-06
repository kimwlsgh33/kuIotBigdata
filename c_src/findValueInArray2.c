#include <stdio.h>
#define SIZE_OF_ARR 10

int findValueInArray(const int *pArr, int size, int value) {
  int i;
  for (i = 0; i < size; ++i) {
    if (pArr[i] == value) {
      break;
    }
  }

  int index = (i < size) ? i : -1;
  return index;
  // return (i < size) ? i : -1;
}

int main(void) {
  int nums[SIZE_OF_ARR] = {50, 90, 10, 20, 40, 80, 70, 100, 30, 60};

  int value;
  printf("input value : ");
  scanf("%d", &value);

  // return value => -1 to identify true or false
  int index = findValueInArray(nums, SIZE_OF_ARR, value);

  if (index != -1) {
    // found
    printf("%d is found. index : %d\n", value, index);
  } else {
    // not found
    printf("%d is not found\n", value);
  }

  return 0;
}
