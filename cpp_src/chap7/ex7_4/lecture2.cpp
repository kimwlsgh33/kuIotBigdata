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
  Power sum(const Power &op);
};

Power Power::sum(const Power &op) {
  Power result(this->kick + op.kick, this->punch + op.punch);
  return result;
}

int main() {
  Power a(3, 5), b(4, 6), c;
  c = a.sum(b);
  a.show();
  b.show();
  c.show();
}
