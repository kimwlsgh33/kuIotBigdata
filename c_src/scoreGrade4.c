#include <stdio.h>
int main(void) {
  // index : 0 ~ 10
  char grades[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};
  
  int score;
  printf("input score: ");
  scanf("%d", &score);

  // grade : 0 ~ 100
  char grade;
  // score / 10 -> 0 ~ 100 / 10 -> 0 ~ 10
  // switch-case vs. indices of a array
  grade = grades[score / 10];

  printf("score : %d --- grade : %c\n", score, grade);

  return 0;
}
