#include <stdio.h>

int main(void) {
  char ch;  // 변수 선언 (ch 라는 변수가 있다)
  ch = 'A'; // 변수 정의 (ch라는 변수는 'A'다)
  char ch2 = 'A'; // 초기화

  printf("문자 입력 : ");
  scanf("%c", &ch);
  printf("ASCII : %d", ch);

  return 0;
}
