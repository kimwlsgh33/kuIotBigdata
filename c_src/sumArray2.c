#include <stdio.h>

// int sumArray(int *pArr) {
// int sumArray(int *pArr, int size) {
// const int *pArr -> read-only (objected value is considered as constant)
// int sumArray(const int *pArr, int size) {
// int pArr[] -> Pointer
// int sumArray(int pArr[], int size) {
// int pArr[10] -> Pointer, the ten has no meaning
int sumArray(int pArr[10], int size) {
  int sum = 0;
  // for (int i = 0; i < 10; ++i) {
  for (int i = 0; i < size; ++i) {
    sum += pArr[i]; // *(pNums + i) : a value of the next element
  }

  return sum;
}

int main(void) {
  int nums[10] = {50, 90, 10, 20, 40, 80, 70, 100, 30, 60};

  int sum; // declaration
  // sum = sumArray(nums);
  sum = sumArray(nums, 10);
  // sum = sumArray(nums + 5, 5); // &nums[5]

  printf("sum: %d\n", sum);

  return 0;
}
