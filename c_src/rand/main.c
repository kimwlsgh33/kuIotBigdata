// <name> : /usr/include/name
#include <stdio.h>
// #include <stdlib.h>
#include <time.h>
// "name" : ./name
#include "rand.h"

// function declaration - 선언
// Why should we declare these functions? We just a user of this functions..
// These information must be given by a function creator.
// void my_srand(int);
// int my_rand(void);

int main(void) {
  /*
  int seed;
  srand(time(NULL), &seed);
  seed = 0;
  int value = rand(&seed);
  */

  // srand(time(NULL));
  // 1. 함수를 사용할려면, 선언 또는, 정의 되어야 한다
  // 2. 함수가 선언되었다면, 어디엔가 함수가 정의 되어야 한다
  my_srand(time(NULL));

  for (int i = 0; i < 10; ++i) {
    // int value = rand();
    int value = my_rand();

    printf("value : %d\n", value);
  }

  return 0;
}
