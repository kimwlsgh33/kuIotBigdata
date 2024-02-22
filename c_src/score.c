#include <stdio.h>

int main(void) {
  // int kor;
  // int eng;
  int kor, eng, math;

  // scanf can be devided by whitespace such as " ", "\n", "\t", etc.
  // printf("input kor : ");
  scanf("%d", &kor);
  // printf("input eng : ");
  scanf("%d", &eng);
  // printf("input math : ");
  scanf("%d", &math);

  int total;

  total = kor + eng + math;

  printf("total : %d\t average : %.2f\n", total, total / 3.0);

  return 0;
}
