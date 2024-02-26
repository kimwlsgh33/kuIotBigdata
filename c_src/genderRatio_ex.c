#include <stdio.h>
int main(void) {
  int men, women;
  scanf("%d %d", &men, &women);

  // double men, women;
  // scanf("%lf %lf", &men, &women);

  // 곱셈에 대한 항등원 (임의의 수 a에 `곱해서` 이전과 같은수가 나오게하는 수
  // `b`) => a * b = a => b = 1
  double menRatio = 1.0 * men / (men + women) * 100;
  // 덧셈에 대한 항등원 (임의의 수 a에 `더해서` 이전과 같은수가 나오게하는 수
  // `b`) => a + b = a => b = 0
  double womenRatio = (0.0 + women) / (men + women) * 100;

  menRatio = (double)men / (double)(men + women) * (double)100;
  womenRatio = (double)women / (men + women) * 100;

  printf("#men : %d\tmen ratio %.2f\n", men, menRatio);
  printf("#women : %d\twomen ratio %.2f\n", women, womenRatio);
  return 0;
}
