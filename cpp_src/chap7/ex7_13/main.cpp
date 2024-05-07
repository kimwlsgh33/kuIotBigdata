#include <iostream>
using namespace std;

namespace jinho {
class Power {
public:
  Power() { cout << "Power() from jinho" << endl; }
};
} // namespace jinho

class Power {
  int m;
public:
  // NOTE: delegating constructor
  // Power() : Power(0, 0) {}
  Power() : m(0) {}
  Power(int m, int n) {}
};

int main() {
  Power a(3, 5), b;
  jinho::Power c;
}
