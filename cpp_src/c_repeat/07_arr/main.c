#include <stdio.h>

int main(void) {
  int size;
  printf("write size :");
  scanf("%d", &size);
  int scores[size];
  int i;
  int total = 0;
  double avg;

  // sizeof calculate the size of all elements in an array
  int num = sizeof(scores) / sizeof(scores[0]);

  for (i = 0; i < size; ++i) {
    // 배열이름 :  배열의 첫번째 element의 주소값
    // 주소값 + 1  : 배열의 elements의 크기 * 1 만큼 증가
    printf("score[%d] : %p\n", i, scores + i);
  }

  for (i = 0; i < size; ++i) {
    scanf("%d", &scores[i]);
  }

  for (i = 0; i < size; ++i) {
    total += scores[i];
  }
  avg = total / (double)size;

  for (i = 0; i < size; ++i) {
    printf("%d\n", scores[i]);
  }
  printf("\n");

  printf("%d\n", total);
  printf("%.1f\n", avg);

  return 0;
}
