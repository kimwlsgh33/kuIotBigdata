#include <iostream>
using namespace std;

class Power {
  int kick;
  int punch;

public:
  Power(int kick, int punch) {
    this->kick = kick;
    this->punch = punch;
  }
  void show() { cout << "kick=" << kick << ',' << "punch=" << punch << endl; }
  bool operator==(const Power &op2);
};

bool Power::operator==(const Power &op2) {
  if (this->kick == op2.kick && this->punch == op2.punch)
    return true;
  return false;
}

int main() {
  Power a(3, 5), b(3, 5);
  a.show();
  b.show();
  if (a == b)
    cout << "두 파워가 같다" << endl;
  else
    cout << "두 파워가 같지 않다" << endl;
}
