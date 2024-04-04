#include <stdio.h>
int main(void) {
  int a;
  int *ptr;
  ptr = &a;
  *ptr = 128; // 0b 00000000 00000000 00000000 10000000

  // printf("포인터로 a값 출력 : %d\n", *ptr);
  // printf("변수명으로 a값 출력 : %d\n", a);
  //
  // printf("포인터 변수 크기 : %ld byte", sizeof(ptr));

  // ============================================
  // access value by various typed pointers
  // ============================================
  // int *iPtr = &a;
  // char *cPtr = &a;
  // printf("int 포인터로 a값 출력 : %d\n", *iPtr);
  // printf("char 포인터로 a값 출력 : %d\n", *cPtr);

  // ============================================
  // declare multiple pointers
  // ============================================
  // b is not a pointer
  // int *pa, b;
  // pa = &a;
  // b = a;

  int *pa, *pb;
  pa = &a;
  pb = &a;

  // ============================================
  // const pointers (read only)
  // ============================================
  const int *cpa = &a;
  // *cpa = 0; => error

  return 0;
}

void usage(void) {}
