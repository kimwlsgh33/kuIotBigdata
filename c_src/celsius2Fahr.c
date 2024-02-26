#include <stdio.h>

int main(void){
  int celsius;
  // celsius = 40;

  // scan format
  // "format specifier" : format what you want to scan
  // &variable : memory where you store
  scanf("%d", &celsius);

  double fahr = 9.0 / 5.0 * celsius + 32;

  printf("celsius : %d ---> fahr : %.1f\n", celsius, fahr);
  
  return 0;
}

void name1(void){}
void name2(void){}
