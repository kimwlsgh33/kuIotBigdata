#include <stdio.h>

void star_display(int row, int col);

int main(void) {
  int row = 3, col = 5;

  star_display(row, col);

  return 0;
}

void star_display(int row, int col) {
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      printf("*");
    }
    printf("\n");
  }
}
