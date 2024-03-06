#include <stdio.h>

void insertionSort(int arr[], int n) {
  int key, j;
  // i : 1 ~ n - 1
  for (int i = 1; i < n; ++i){
    key = arr[i];
    // j : 0 ~ n - 2
    j = i - 1;

    /* Move elements of arr[0..i-1], that are greater then key, to one position ahead of their current position */
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
}

int main(void) {
  int arr[10] = {50, 90, 10, 20, 40, 80, 70, 100, 30, 60};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Original array: \n");
  printArray(arr, n);
  
  insertionSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;
}
