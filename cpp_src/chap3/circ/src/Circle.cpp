#include "Circle.h"
#include <iostream>
using namespace std;
Circle::Circle() {
  radius = 1;
  cout << "반지름 " << radius;
  cout << " 원생성" << endl;
}

Circle::Circle(int r) {
  radius = r;
  cout << "반지름 " << radius;
  cout << " 원생성" << endl;
}

double Circle::getArea() { return 3.14 * radius * radius; }
