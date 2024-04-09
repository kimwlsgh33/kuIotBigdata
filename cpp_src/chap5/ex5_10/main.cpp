#include <cstring>
#include <iostream>
using namespace std;

class Person {
  int id;
  char *name;

public:
  Person(int id, const char *name);
  Person(const Person &other);
  ~Person();

  int getId() { return this->id; }
  const char *getName() { return this->name; }
  void show() { cout << id << ',' << name << endl; }
  void changeName(const char *name) {
    // if (strlen(this->name) < strlen(name))
    //   return;
    // strcpy(this->name, name);
    // return;

    delete this->name;
    int len = strlen(name);
    this->name = new char[len + 1];
    strcpy(this->name, name);
  }
};

Person::Person(int id, const char *name) {
  this->id = id;
  // strlen doesn't contain '\0'
  int len = strlen(name);
  // +1 for store '\0'
  this->name = new char[len + 1];
  strcpy(this->name, name);
}

Person::Person(const Person &other) {
  id = other.id;
  int len = strlen(name);
  name = new char[len + 1];
  strcpy(name, other.name);
}

Person::~Person() {
  if (name)
    delete[] name;
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
