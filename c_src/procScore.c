#include <stdio.h>

int main(void) {
  // int score1, score2, score3, score4, score5;
  int scores[5]; // 0=====1=====2=====3=====4=====

  // scanf("%d", &score1);
  // scanf("%d", &score2);
  // scanf("%d", &score3);
  // scanf("%d", &score4);
  // scanf("%d", &score5);

  // scanf("%d", &scores[0]);
  // scanf("%d", &scores[1]);
  // scanf("%d", &scores[2]);
  // scanf("%d", &scores[3]);
  // scanf("%d", &scores[4]);

  for (int i = 0; i < 5; ++i) {
    scanf("%d", &scores[i]);
  }

  // int sum = score1 + score2 + score3 + score4 + score5;
  int sum;
  sum = 0;
  for (int i = 0; i < 5; ++i) {
    sum = sum + scores[4];
  }

  // 형변환
  double average = (double)sum / 5;

  printf("sum: %d\taverage: %.2f\n", sum, average);

  return 0;
}

/*
 * printf => fprintf(stdout, ...)
 * scanf => fscanf(stdin, ...)
 *
 * fprintf : file print by format
 * fscanf : file scan by format
 *
 * UNIX는 모든 장치를 파일로 다룬다
 * ls /dev (device) => 장치파일
 *
 * (redirect)
 * ./executionfile < input file > output file
 * ./procScore < score.dat > score.out
 * */
