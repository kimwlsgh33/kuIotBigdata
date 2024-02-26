#include <stdio.h>
int main(void){
  int num;
  printf("input num: ");
  scanf("%d", &num);
  printf("%d : %d\n", num, num % 2);
  return 0;
}
