#include <iostream>
using namespace std;

class Circle {
private:
  int radius;

public:
  Circle();
  Circle(int radius);
  ~Circle();
  double getArea() { return 3.14 * radius * radius; }
  int getRadius() { return radius; }
  void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle() {
  radius = 1;
  cout << this << " 생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int radius) {
  this->radius = radius;
  cout << this << " 생성자 실행 radius = " << radius << endl;
}

Circle::~Circle() {
  cout << this << " 소멸자 실행 radius = " << radius << endl;
}

void increase(Circle c) {
  int radius = c.getRadius();
  c.setRadius(++radius);
}

int main() {
  Circle waffle(30);
  increase(waffle);
  cout << waffle.getRadius() << endl;
}
