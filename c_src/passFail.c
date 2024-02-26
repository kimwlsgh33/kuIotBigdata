#include <stdio.h>
int main(void){
  int score;
  printf("input score: "); // prompt
  scanf("%d", &score);

  printf("%d : %d\n", score, score >= 60);
  return 0;
}
