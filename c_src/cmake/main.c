#include "bar.h"
#include "foo.h"
#include <stdio.h>

int main(void) {
  printf("String from Main\n");
  foo();
  bar();
  return 0;
}
