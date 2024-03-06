#include <stdio.h>

char getScoreGrade(int score, const char *grades) {
  return grades[score/10];
}

int main(void) {
  char grades[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};
  int score;
  printf("input score: ");
  scanf("%d", &score);

  // grade : 0 ~ 100
  char grade;
  // score / 10 -> 0 ~ 100 / 10 -> 0 ~ 10
  // switch-case vs. indices of a array
  // grade = grades[score / 10];
  grade = getScoreGrade(score, grades);

  printf("score : %d --- grade : %c\n", score, grade);

  return 0;
}
