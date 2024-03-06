#include <stdio.h>

int power(int base, int exponent) {
// long long power(int base, int exponent) {
  int result = 1; // hang dung won multiply
  // long long result = 1LL;
  for (int i = 0; i < exponent; ++i) {
    result *= base;
  }
  return result;
}

int main(void) {
  for (int i = 0; i <= 32; ++i) {
    int result = power(2, i);
    // long long result = power(2, i);
    printf("2 to the power of %d : %d\n", i, result);
    // printf("2 to the power of %d : %lld\n", i, result);
  }
  
  return 0;
}
