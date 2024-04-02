#include <iostream>
using namespace std;

class Tower {
public:
  int height;
  int getHeight();
  Tower();
  Tower(int h);
  ~Tower();
};

// using `g++ -std=c++11` to compile this file
// you should define default constructor
Tower::Tower() : Tower(1) {}
Tower::Tower(int h) { height = h; }
Tower::~Tower() { cout << "소멸" << height << endl; }

int Tower::getHeight() { return height; }

int main(void) {
  Tower myTower;
  Tower seoulTower(100);
  cout << "높이는 " << myTower.getHeight() << "미터" << endl;
  cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}
