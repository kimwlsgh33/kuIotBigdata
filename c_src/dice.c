#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int num;
  // int rs_scan;
  // scanf("%d", &num);
  // printf("rs_scan : %d\n", rs_scan);

  // srand(time(time_t *timer))
  srand(time(NULL)); // seed

  for (int i = 1; i <= 10; ++i) {
    int dice = rand() % 6 + 1; // random number : 난수
    // recent rand : 0.0 <= num <= 1.0
    printf("%d\n", dice);
  }

  return 0;
}
