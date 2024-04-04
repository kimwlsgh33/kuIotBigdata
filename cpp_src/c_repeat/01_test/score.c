#include <stdio.h>

int main(void) {
  int kor = 3, eng = 5, mat = 4; // 학점
  
  int credits;
  int res;

  double kscore = 3.8, escore = 4.4, mscore = 3.9; // 평점
  double grade;

  credits = kor + eng + mat;              // 학점 총합
  grade = (kscore + escore + mscore) / 3; // 평점 평균

  // printf("credits : %d, grade : %.1f\n", credits, grade);
  res = credits >= 10 && grade > 4.0;
  printf("%d\n", res);

  return 0;
}
