#include <iostream>
using namespace std;

class Circle {
  int radius;

public:
  // member functions always have `this` pointer by default
  Circle(int radius) {
    this->radius = radius;
    cout << radius << " default constructor!\n";
  }
  // you must prefix `&` to use object as a parameter
  Circle(const Circle &other) {
    this->radius = other.radius;
    cout << radius << " copy constructor!\n";
  }
  double getArea() { return 3.14 * radius * radius; }
};

int main() {
  Circle src(30);
  Circle dst(src); // copy by constructor

  cout << "src : " << src.getArea() << "\tdst : " << dst.getArea() << '\n';
}
