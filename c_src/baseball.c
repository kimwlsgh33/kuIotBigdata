#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // matched : strike
  // included : ball
  int question[3];
  int answer[3];

  srand(time(NULL));
  // question[i] <-- unique! [1, 9] random num
  question[0] = rand() % 9 + 1;
  // i: 1 ~ 2
  for (int i = 1; i < 3; ++i) {
    int tmp = rand() % 9 + 1;
    // j: 0 ~ 2
    for (int j = 0; j < 3; ++j) {
      if (tmp == question[j]) {
        --i;
        break; // break `j` for statements
      }
    }
    question[i] = tmp;
  }

  int strike;
  int ball;
  int count = 0;

  while (strike != 3) {
    // scanf("%d", answer[]);
    printf("input answer: ");
    // for (int i = 0; i < 3; ++i) {
    //   scanf("%d", &answer[i]);
    // }
    scanf("%d %d %d\n", &answer[0], &answer[1], &answer[2]);

    // strike, ball
    for (int i = 0; i < 3; ++i) {
      if (answer[i] == question[i]) {
        ++strike;
      } else {
        // if answer[i] in question
        for (int j = 0; j < 3; ++j) {
          if (answer[i] == question[j]) {
            ++ball;
            break;
          }
        }
      }
    }

    if (strike == 3) {
      break;
    }
    printf("%d strike\t%d ball\n", strike, ball);
    strike = 0;
    ball = 0;
    ++count;
  }

  printf("3 Strike!\tcount: %d\n", count);

  return 0;
}
