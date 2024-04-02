#include <iostream>
using namespace std;

// class definition
class Circle {
public:
  int radius;       // member variable declaration (noun)
  double getArea(); // member function declaration (verb)
  Circle(); // constructor declaration - this must be the same with the class
            // name
  // function overloading
  Circle(int r);

private: // encapsulation
};
// you should write semicolon at the end of class

// constructor definition - initilize instances of class
Circle::Circle() {
  radius = 1;
  cout << "반지름 :  " << radius << " 원 생성" << endl;
}

Circle::Circle(int r) {
  radius = r;
  cout << "반지름 :  " << radius << " 원 생성" << endl;
}

// member function definition
double Circle::getArea(void) {
  // fetch member variable `radius` from Circle class
  return 3.14 * radius * radius;
};

int main(void) {
  // create local variable
  int radius;
  // create local instance
  Circle donut;
  // donut.radius = 1; // access to a member
  // cout << "도넛의 면적 : " << donut.getArea() << endl;

  // create local instance like function call
  Circle pizza(3);
  // pizza.radius = 3;
  // cout << "피자의 면적 : " << pizza.getArea() << endl;
}
