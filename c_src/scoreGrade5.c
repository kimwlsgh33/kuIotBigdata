#include <stdio.h>

// 기능을 분리시킬수 있다 - 코드관리, 가독성
char getScoreGrade(int score) {
  char grades[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};
  return grades[score / 10];
}

int main(void) {
  // char grades[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};
  int score;
  printf("input score: ");
  scanf("%d", &score);

  // grade : 0 ~ 100
  char grade;
  // score / 10 -> 0 ~ 100 / 10 -> 0 ~ 10
  // switch-case vs. indices of a array
  // grade = grades[score / 10];
  grade = getScoreGrade(score);

  printf("score : %d --- grade : %c\n", score, grade);

  return 0;
}
