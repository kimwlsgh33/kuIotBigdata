#include <stdio.h>
int main(void) {
  int score;
  printf("input score: ");
  scanf("%d", &score);

  /*
  // (condition)
  if (score >= 60) {
    // condition true
    printf("score : %d --- pass\n", score);
  } else {
    // condition false
    printf("score : %d --- fail\n", score);
  }
  */

  // conditional expression operator
  // if `condition` (?) then `expression1` otherwise(:) `expression2`
  printf("score : %d --- %s\n", score, (score >= 60) ? "pass" : "fail");
  return 0;
}
