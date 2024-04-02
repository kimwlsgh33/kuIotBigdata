#include <stdio.h>
int main(void) {
  int res;

  res = sizeof(short) > sizeof(long);

  printf("%s\n", res ? "short" : "long");
  return 0;
}
