#include <iostream>
using namespace std;

class Person {
public:
  int money;
  void addMoney(int money);

  static int sharedMoney;
  static void addShared(int n) { sharedMoney += n; }
};

int Person::sharedMoney = 10;

void Person::addMoney(int money) { this->money += money; }

int main() {
  cout << Person::sharedMoney << endl;
  Person::addShared(100);
  cout << Person::sharedMoney << endl;

  Person han;
  han.money = 100;
  han.sharedMoney = 200;

  cout << han.sharedMoney << endl;
  cout << Person::sharedMoney << endl;
}
