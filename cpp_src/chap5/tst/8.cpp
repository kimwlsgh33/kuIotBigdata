#include <iostream>
using namespace std;

class MyIntStack {
  int *p;
  int size;
  int tos;

public:
  MyIntStack();
  MyIntStack(int size);
  MyIntStack(const MyIntStack &s);
  ~MyIntStack();
  bool push(int n);
  bool pop(int &n);
  void show();
};

MyIntStack::MyIntStack() : MyIntStack(10) {}
MyIntStack::MyIntStack(int size) {
  p = new int[size]{0};
  this->size = size;
  tos = 0;
}
MyIntStack::~MyIntStack() {
  if (p)
    delete[] p;
}
MyIntStack::MyIntStack(const MyIntStack &s) {
  size = s.size;
  p = new int[size]{0};
  // 배열의 요소값 복사 (깊은복사)
  for (int i = 0; i < size; ++i) {
    p[i] = s.p[i];
  }
  tos = s.tos;
}

bool MyIntStack::push(int n) {
  if (tos == size)
    return false;

  p[tos++] = n;
  return true;
}

bool MyIntStack::pop(int &n) {
  if (tos == 0)
    return false;
  p[tos] = 0;
  n = p[--tos];
  return true;
}

void MyIntStack::show() {
  cout << "Stack\t: ";
  for (int i = 0; i < size; ++i) {
    cout << p[i] << '\t';
  }
  cout << "\nTOS\t: " << tos << endl;
}

int main() {
  MyIntStack a(10);
  a.push(10);
  a.push(20);
  a.show();
  MyIntStack b = a;
  b.push(30);

  int n;
  a.pop(n);
  cout << "스택 a에서 팝한 값" << n << endl;
  b.pop(n);
  cout << "스택 b에서 팝한 값" << n << endl;
}
