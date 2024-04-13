#include <iostream>
using namespace std;

class Point {
  int x, y;

public:
  Point();
  void set(int x, int y) {
    this->x = x;
    this->y = y;
  }
  void showPoint() { cout << "(" << x << "," << y << ")" << endl; }
};

Point::Point() {
  x = 0;
  y = 0;
}

class ColorPoint : public Point {
  string color;

public:
  void setColor(string color) { this->color = color; }
  void showColorPoint();
};

void ColorPoint::showColorPoint() {
  // this->x  // you cannot access private member of base class
  cout << color << ":";
  showPoint();
}

int main() {
  Point p;
  ColorPoint cp;
  cp.set(3, 4);
  cp.setColor("Red");
  cp.showColorPoint();
}
