#include <stdio.h>
int main(void) {
  int num;
  printf("input num: ");
  scanf("%d", &num);

  // you can skip the brace if is a single condition
  if (num > 0) {
    // positive
    printf("%d is a positive number\n", num);
  } else if (num < 0) { // use `if` after `else` => else if
    // negative
    printf("%d is a negative number\n", num);
  } else {
    /*
     * if { ... } else { ... }
     * */
    // zero
    printf("%d is a zero number\n", num);
  }
  return 0;
}
