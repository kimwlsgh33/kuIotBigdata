#include <iostream>
using namespace std;

class Circle {
  int radius;

public:
  Circle(int radius = 0) { this->radius = radius; }
  int getRadius() { return radius; }
  void setRadius(int radius) { this->radius = radius; }
  double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
  string name;

public:
  string getName() { return name; }
  void setName(const string &name) { this->name = name; };
  // void setInfo(int radius, const string &name);
  // void show();
};

// void NamedCircle::setInfo(int radius, const string &name) {
//   this->name = name;
//   setRadius(radius);
// }

int main() {
  NamedCircle pizza[5];
  cout << "5개의 정수 반지름과 원의 이름을 입력하세요\n";

  int radius;
  string name;

  int max_idx = 0;
  for (int i = 0; i < 5; ++i) {
    cout << i + 1 << ">> ";
    cin >> radius >> name;
    // pizza[i].setInfo(radius, name);
    pizza[i].setRadius(radius);
    pizza[i].setName(name);
    if(pizza[max_idx].getRadius() < pizza[i].getRadius())
      max_idx = i;
  }

  // int max_idx = 0;
  // for (i = 1; i < 5; ++i) {
  //   if (pizza[max_idx].getRadius() < pizza[i].getRadius())
  //     max_idx = i;
  // }
  cout << "가장 면적이 큰 피자는 " << pizza[max_idx].getName() << "입니다";
}
