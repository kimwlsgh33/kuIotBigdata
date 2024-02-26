#include <stdio.h>
int main(void) {
  int men, women;
  scanf("%d %d", &men, &women);
  double sum = men + women;
  // ratio = num / sum = x / 100
  // x = 100 * (sum / num)
  printf("#men : %d\tmen ratio %.2f\n", men, 100 * (men / sum));
  printf("#women : %d\twomen ratio : %.2f\n", women, 100 * (women / sum));
  return 0;
}
