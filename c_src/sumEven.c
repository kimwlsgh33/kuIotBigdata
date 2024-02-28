#include <stdio.h>
int main(void) {
  int sum = 0;
  // int i = 1;
  int i = 2;

  int limit;
  printf("input a limit: ");
  scanf("%d", &limit);

  while (i <= limit) {
    // if (i % 2 == 0) {
    //   sum = sum + i;
    // }
    
    // sum = (i % 2) ? sum : sum + i;
    
    sum = sum + i;
    i = i + 2; // you don't need to add 1
  }

  printf("sum of even[1, %d] : %d\n", limit, sum);
  return 0;
}
