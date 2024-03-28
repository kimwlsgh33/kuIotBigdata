#include <stdio.h>

int main(void) {
  int a = 5, b = 5;
  int pre, post;

  pre = (++a) * 3;
  // a = a + 1;
  // pre = a * 3;
  post = (b++) * 3;
  // post = b * 3;
  // b = b + 1;

  printf("pre: %d\n", pre);
  printf("post: %d\n", post);
  printf("a : %d\n", a);
  printf("b : %d\n", b);

  ++a; // a = a + 1;
  --b; // b = b - 1;

  
  // 횟수가 정해져 있을때 => for
  for (int i = 0; i < 5; i++) {
    printf("i : %d\n", i);
  }


  return 0;
}
