#include <iostream>
using namespace std;

class PrivateAccessError {
public: // this can be called by every functions
  int b;
  void g();
  PrivateAccessError();
  PrivateAccessError(int x);

private: // only call by member functions
  int a;
  void f();
};

PrivateAccessError::PrivateAccessError() {
  a = 1;
  b = 1;
}
PrivateAccessError::PrivateAccessError(int x) {
  a = x;
  b = x;
}

void PrivateAccessError::f() {
  a = 5;
  b = 5;
}
void PrivateAccessError::g() {
  a = 6;
  b = 6;
}

int main(void) {
  PrivateAccessError objA, objB(100);
  // objA.a = 10;
  // objB.a = 10;
}
