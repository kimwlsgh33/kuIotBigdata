#include <stdio.h>

int main(void) {
  // decimal(10)
  printf("%d %d %d\n", 100, 0144, 0x64);
  // decimal(10), octal(8), hexa-decimal(16)
  printf("%d 0%o 0x%x\n", 100, 0144, 0x64);

  // ASCII
  printf("%d %d %d\n", 'A', 'a', '0'); // integer format
  printf("%c %c %c\n", 65, 97, 48);    // character format
  printf("%c %c %c\n", 'A', 'a', '0'); // character format

  printf("%c %c %c\n", 65, 66, 67);
  printf("%c %c %c\n", 'A', 'A' + 1, 'A' + 2);

  // long long
  printf("%lldLL\n", 100000000LL);

  // float
  printf("%f %fF\n", 3.141592, 2.718F);

  // string
  printf("%s\n", "hello, world");
  return 0;
}
