#include <stdio.h>

int sumMatrix(int (*pArr)[4], int row, int col) {
  int sum = 0;
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      sum += pArr[i][j];  // *(pArr[i] + j)
                          // *(*(pArr + i) + j)
    }
  }
  return 0;
}

int main(void) {
  int matrix[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  int sum = sumMatrix(matrix, 3, 4); // &matrix[0]

  printf("sum : %d\n", sum);

  return 0;
}
