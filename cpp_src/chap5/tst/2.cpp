#include <iostream>
using namespace std;

void half(double *n) {
  *n = *n / 2;
  cout << *n << endl;
  cout << "*n address: " << &n << endl;
}

// overload
void half(double &n) {
  n = n / 2;
  cout << n << endl;
  cout << "&n address: " << &n << endl;
}

int main() {
  double n = 20;
  cout << "n address: " << &n << endl;
  half(n);
  half(&n);
  cout << n;
}
