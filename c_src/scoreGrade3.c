#include <stdio.h>
int main(void) {
  // input part
  int score;
  printf("input score: ");
  scanf("%d", &score);

  // condition part
  char grade;
  // assembling to the ten place value by devide by 10
  // `switch-case` has less evaluation than `if-else` => performance
  // optimization
  // less than, greater than vs. is equal (you can use bit operator `^`)
  switch (score / 10) {
  case 10: // This doesn't stop until encounter the `break`
  case 9:
    grade = 'A';
    break; // Jumping to the end of the switch
  case 8:
    grade = 'B';
    break;
  case 7:
    grade = 'C';
    break;
  case 6:
    grade = 'D';
    break;
  default: // 5, 4, 3, 2, 1, 0
    grade = 'F';
  }

  // output part
  printf("score : %d --- grade : %c\n", score, grade);

  return 0;
}
