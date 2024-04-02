#include <iostream>
using namespace std;

#include "Adder.h"
#include "Calculator.h"

void Calculator::run() {
  cout << "두 개의 수를 입력하세요>>";
  int a, b;
  cin >> a >> b;
  Adder addr(a, b);
  cout << addr.process();
}
