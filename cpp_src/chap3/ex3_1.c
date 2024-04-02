#include <stdio.h>

double getArea(int radius);

int main(void) {
  int donutRds = 1;
  printf("도넛의 면적 : %.2f\n", getArea(donutRds));

  int pizzaRds = 2;
  printf("피자의 면적 : %.2f\n", getArea(pizzaRds));
  return 0;
}

double getArea(int radius){
  // you have to define correspond parameter
  return 3.14 * radius * radius;
};
