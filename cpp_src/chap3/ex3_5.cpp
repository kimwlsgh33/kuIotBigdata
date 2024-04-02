#include <iostream>
using namespace std;

class Point {
public:
  int x, y;
  Point();
  Point(int x, int y);
};

Point::Point() : Point(0, 0) {}
Point::Point(int valx, int valy) {
  x = valx;
  y = valy;
}

int main(void) {
  Point origin;
  Point target(10, 20);
}
