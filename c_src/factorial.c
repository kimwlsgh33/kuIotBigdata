#include <stdio.h>

// int factorial(int n) {
long long factorial(int n) {
  // int result = 1;
  long long result = 1;
  for (int i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

int main(void) {
  for (int i = 0; i < 100; ++i) {
    // int result = factorial(i);
    long long result = factorial(i);

    // printf("%d! : %d\n", i, result);
    printf("%d! : %lld\n", i, result);
  }
  return 0;
}
