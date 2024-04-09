#include <iostream>
#include <string>
using namespace std;

class Person {
  int id;
  string name;

public:
  Person(int id, string name);
  Person(const Person &other);

  int getId() { return this->id; }
  string getName() { return this->name; }
  void show() { cout << id << ',' << name << endl; }
  void changeName(string name) { this->name = name; }
};

Person::Person(int id, const string name) {
  this->id = id;
  this->name = name;
}

Person::Person(const Person &other) {
  id = other.id;
  name = other.name;
}

int main() {
  Person father(1, "Kitae");
  Person daughter(father);

  cout << "daughter 객체 생성 직후 ----" << endl;
  father.show();
  daughter.show();

  daughter.changeName("Grace");
  cout << "daughter 이름을 Grace로 변경후 ----" << endl;
  father.show();
  daughter.show();
}
