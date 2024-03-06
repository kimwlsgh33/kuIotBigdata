#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE_OF_DICE 7
#define REPEAT_NUM 1000

int main(void) {
  int nums[SIZE_OF_DICE] = {0};
  // index : 0 ~ 5
  // int nums[6] = {0};
  // int nums[6];
  // for (int i = 0; i < 6; ++i) {
  //   nums[i] = 0; // initialization
  // }

  srand(time(NULL)); // give `rand()` a seed
  for (int i = 1; i <= REPEAT_NUM; ++i) {
    // dice: 0 ~ 5
    // int dice = rand() % 6;
    // int dice = rand() % SIZE_OF_DICE;
    int dice = rand() % SIZE_OF_DICE + 1;
    // --> nums[0 ~ 5]
    ++nums[dice];
    // nums[dice - 1] = nums [dice - 1] + 1;
  }

  // for (int i = 0; i < 6; ++i) {
  // for (int i = 0; i < SIZE_OF_DICE; ++i) {
  for (int i = 1; i < SIZE_OF_DICE; ++i) {
    // printf("%d --- %d\n", i + 1, nums[i]);
    printf("%d --- %d\n", i, nums[i]);
  }

  return 0;
}
