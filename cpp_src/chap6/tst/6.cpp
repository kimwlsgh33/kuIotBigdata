#include <iostream>
using namespace std;

class ArrayUtility2 {
  static int *pArr;
  ~ArrayUtility2();

public:
  static int *concat(int s1[], int s2[], int size);
  static int *remove(int s1[], int s2[], int size, int &retSize);
};

int *ArrayUtility2::concat(int s1[], int s2[], int size) {
  pArr = new int[size];

  for (int i = 0; i < size; ++i) {
    if (i < size / 2)
      pArr[i] = s1[i];
    else
      pArr[i] = s2[i];
  }

  return pArr;
}

ArrayUtility2::~ArrayUtility2() { delete[] pArr; }

int main() {
  cout << "정수를 5 개 입력하라. 배열 x에 삽입한다>>";
  int x[5];
  for (int i = 0; i < 5; ++i) {
    cin >> x[i];
  }
  cout << "정수를 5 개 입력하라. 배열 y에 삽입한다>>";
  int y[5];
  for (int i = 0; i < 5; ++i) {
    cin >> y[i];
  }

  cout << "합친 정수 배열을 출력한다\n";
  int *p = ArrayUtility2::concat(x, y, 10);
  for (int i = 0; i < 10; ++i) {
    cout << p[i];
  }

  cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 2\n";
}
