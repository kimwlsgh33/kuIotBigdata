#include <stdio.h>

int main(void) {
  // 문자 배열(array of character) !=  문자열(string '\0')
  char str[] = {'a', 'p', 'p', 'l', 'e', 'j', 'a', 'm'};

  // 배열의 타입이 바뀔수 있다 => / sizeof(element)
  // 배열에 무조건 0은 있다 => [0]
  int size = sizeof(str) / sizeof(str[0]);

  printf("size : %d\n", size);
  return 0;
}
