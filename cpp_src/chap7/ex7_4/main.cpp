#include <iostream>
using namespace std;

class Power {
  int kick;
  int punch;

public:
  Power(int kick = 0, int punch = 0) {
    this->kick = kick;
    this->punch = punch;
  };
  void show() { cout << "kick=" << kick << ',' << "punch=" << punch << endl; };
  Power operator+(const Power &op2);
  Power operator+(int op2);
  Power operator-(const Power &op2);
  Power operator+=(const Power &op2);
};

Power Power::operator+(const Power &op2) {
  Power tmp;
  tmp.kick = this->kick + op2.kick;
  tmp.punch = this->punch + op2.punch;
  return tmp;
}

Power Power::operator+(int op2) {
  Power tmp;
  tmp.kick = this->kick + op2;
  tmp.punch = this->punch + op2;
  return tmp;
};

Power Power::operator-(const Power &op2) {
  Power tmp;
  tmp.kick = this->kick - op2.kick;
  tmp.punch = this->punch - op2.punch;
  return tmp;
}

Power Power::operator+=(const Power &op2) {
  kick += op2.kick;
  punch += op2.punch;
  return *this;
}

int main() {
  Power a(3, 5), b(4, 6), c, d, e;
  a.show();
  b.show();

  c = a + b;
  c.show();
  c = a + 2;
  c.show();

  d = a - b;
  d.show();

  e = a += b;
  a.show();
  e.show();
}
