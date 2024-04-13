#include <stdio.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

/*
* low : 
* 1. first index
* 2. first index
* 3. returned index + 1
*
* high : 
* 1. last index
* 2. returned index - 1
* 3. last index
*
* i : [-1]
*/
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // Select the pivot element (usually the last element)
  int i = (low - 1);     // Index of the smaller element

  // j [low, high)
  for (int j = low; j < high; j++) {
    // If current element is smaller than or equal to pivot
    if (arr[j] <= pivot) {
      i++; // Increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

/*
* low : first index
* high : last index
*/
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    // pi is partitioning index, arr[pi] is now at right place
    int pi = partition(arr, low, high);

    // Separately sort elements before partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  // initialize array
  int arr[] = {10, 7, 8, 9, 1, 5};
  // calculate a number of elements.
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Unsorted array : \n");
  printArray(arr, n);

  // address, first index, last index
  quickSort(arr, 0, n - 1);

  printf("Sorted array : \n");
  printArray(arr, n);
  return 0;
}
