#include <iostream>
using namespace std;

class Circle {
public:
  int radius;
  Circle();
  Circle(int r);

  double getArea(void);
  void setRadius(int r);
};

Circle::Circle() { radius = 1; }
Circle::Circle(int r) { radius = r; }
double Circle::getArea(void) { return 3.14 * radius * radius; }
void Circle::setRadius(int r) { radius = r; }

int main() {
  Circle circleArray[3];

  circleArray[0].setRadius(10);
  circleArray[1].setRadius(20);
  circleArray[2].setRadius(30);

  for (int i = 0; i < 3; ++i) {
    cout << "*Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;
  }

  Circle *p;
  p = circleArray;
  for (int i = 0; i < 3; ++i) {
    cout << "Circle" << i << "의 면적은 " << p->getArea() << endl;
    p++;
  }
}
