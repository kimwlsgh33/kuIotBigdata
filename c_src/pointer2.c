#include <stdio.h>
int main(void) {
  int a= 100;
  int nums2[5];
  
  // 아무것도 포인트하지 않겠다. 
  // 가리킬 대상을 지정하지 않겠다
  int *p = NULL;

  p = &a;
  *p = 200;


  p = &nums2[2];
  *p = 200;

  printf("a: %d\n", a);
  printf("nums2[2]: %d\n", nums2[2]);

  return 0;
}
