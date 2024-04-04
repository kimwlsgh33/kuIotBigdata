#include <iostream>
using namespace std;

int main() {
  int *arr = new int[5];

  cout << "정수 5개 입력>> ";
  for (int i = 0; i < 5; ++i) {
    cin >> arr[i];
  }

  int sum = 0;
  for (int i = 0; i < 5; ++i) {
    sum += arr[i];
  }

  cout << (double)sum / 5;

  delete[] arr;
}
