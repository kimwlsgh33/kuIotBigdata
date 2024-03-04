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

  // question[1] = rand() % 9 + 1;
  // while(question[0] == question[1]) {
  //   question[1] = rand() % 9 + 1;
  // }

  do {
    question[1] = rand() % 9 + 1;
  } while (question[0] == question[1]);

  // question[2] = rand() % 9 + 1;
  // while(question[2] == question[0] || question[2] == question[1]) {
  //   question[2] = rand() % 9 + 1;
  // }

  do {
    question[2] = rand() % 9 + 1;
  } while (question[2] == question[0] || question[2] == question[1]);

  // printf("question : %d %d %d\n", question[0], question[1], question[2]);

  int strike;
  int ball;
  int count = 0;

  while (strike != 3) {
    // scanf("%d", answer[]);
    printf("input answer: ");
    scanf("%d %d %d", &answer[0], &answer[1], &answer[2]);

    // strike, ball
    strike = ball = 0;
    ++count;

    for (int i = 0; i < 3; ++i) {
      // if answer[i] in question
      for (int j = 0; j < 3; ++j) {
        if (answer[i] == question[j]) {
          if (i == j) {
            ++strike;
          } else {
            ++ball;
          }
        }
      }
    }

    if (strike == 3)
      break;

    printf("#strike : %d\t#ball : %d\n", strike, ball);
  }

  printf("congratuation! your count : %d\n", count);

  return 0;
}
