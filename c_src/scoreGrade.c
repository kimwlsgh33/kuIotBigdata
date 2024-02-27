#include <stdio.h>
int main (void){
  int score;
  printf("input score: ");
  scanf("%d", &score);

  if (score >= 90) {
    printf("score : %d, A\n", score);
  } else if (score >= 80 /* && score < 90 */) {
    printf("score : %d, B\n", score);
  } else if (score >= 70 ) {
    printf("score : %d, C\n", score);
  } else if (score >= 60 ) {
    printf("score : %d, D\n", score);
  } else {
    printf("score : %d, F\n", score);
  }
  
  return 0;
}
