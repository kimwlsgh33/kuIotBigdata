#include <stdio.h>
// #define : define macro - increase productivity
// #define PI 3.14 
#define PI 3.141592

int main(void){
  int radius;
  printf("input radius : ");
  scanf("%d", &radius);

  // printf("area of circle : %.1f\n", radius * 3.14);
  printf("area of circle : %.1f\n", radius * PI);

  return 0;
}
