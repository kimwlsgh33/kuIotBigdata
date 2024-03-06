#include <stdlib.h>
#include <time.h>

// static int count;

int getSerialNumber(void) {
  // if it's global and if it's used by only one function,
  // use static local variable
  static int count;
  ++count;
  return count;
};
