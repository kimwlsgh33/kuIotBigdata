// 1 ~ 45 => 6 + 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int lotto[7];

  srand(time(NULL));
  // input
  lotto[0] = rand() % 45 + 1;

  // do {
  //   lotto[1] = rand() % 45 + 1;
  // } while (lotto[1] == lotto[0]);
  //
  // do {
  //   lotto[2] = rand() % 45 + 1;
  // } while (lotto[2] == lotto[0] || lotto[2] == lotto[1]);
  // ...
  // i: 1 -> j: 0
  // i: 2 -> j: 0, 1
  // i: 3 -> j: 0, 1, 2
  // j => [0, i-1] => [0, i)

  // i: 1 ~ 6
  for (int i = 1; i < 7; ++i) {
    int tmp = rand() % 45 + 1;
    // if (tmp in lotto) {
    //   --i;
    // }
    // j: [0, i)
    for (int j = 0; j < i; ++j) {
      if (tmp == lotto[j]) {
        --i;
        break; // break the nested loop as soon as a duplication is found.
      }
    }
    lotto[i] = tmp;
  }

  // output
  printf("lotto --> ");
  for (int i = 0; i < 6; ++i) {
    printf("%d ", lotto[i]);
  }
  printf("+ bonous: %d\n", lotto[6]);
  return 0;
}
