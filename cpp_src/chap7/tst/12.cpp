#include <iostream>
using namespace std;

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

class SortedArray {
  int size;
  // always be ascendin order
  int *p;
  void sort();

public:
  SortedArray();
  SortedArray(SortedArray &src);
  SortedArray(int p[], int size);
  ~SortedArray();
  SortedArray operator+(SortedArray &op2);
  SortedArray &operator=(const SortedArray &op2);
  void show();
};

SortedArray::SortedArray(int p[], int size) {
  this->p = new int[size]{0};
  for (int i = 0; i < size; ++i) {
    this->p[i] = p[i];
  }
  sort();
  this->size = size;
}
SortedArray SortedArray::operator+(SortedArray &op2) {
  SortedArray tmp;
  int total_size = this->size + op2.size;
  tmp.p = new int[total_size]{0};
  for (int i = 0; i < total_size; ++i) {
    if (i < this->size)
      tmp.p[i] = this->p[i];
    else
      tmp.p[i] = op2.p[i];
  }
  tmp.sort();
  return tmp;
}

SortedArray &SortedArray::operator=(const SortedArray &op2) {
  this->p = new int[op2.size]{0};
  for (int i = 0; i < op2.size; ++i) {
    this->p[i] = op2.p[i];
  }
  return *this;
}

SortedArray::~SortedArray() { delete[] p; }

void SortedArray::sort() {
  int max_idx = 0;
  int tmp, j;
  // {2, 20, 6}
  // compare 0, 1 -> store max value's index -> iterate to last index -> swap
  // max value with last -> last - 1 -> loop
  for (int i = 0; i < size; ++i) {
    for (j = 0; j < i + 1; ++j) {
      if (p[j] < p[j + 1]) {
        max_idx = j;
      }
    }

    if (max_idx != j) {
      tmp = p[max_idx];
      p[max_idx] = p[j];
      p[j] = tmp;
    }
  }
}

void SortedArray::show() {
  cout << "배열 출력 : ";
  for (int i = 0; i < size; ++i)
    cout << p[i] << ' ';
  cout << endl;
}

int main() {
  int n[] = {2, 20, 6};
  int m[] = {10, 7, 8, 30};
  SortedArray a(n, 3), b(m, 4), c;

  // this cannot call copy constructor
  c = a + b;

  a.show();
  b.show();
  c.show();
}
