#include <iostream>
#include <string>
using namespace std;

int main() {
  string a("Hello C++");
  cout << a.length() << endl; // 9
  a.append("!!");
  cout << a << endl;           // "Hello C++!!"
  cout << a.at(6) << endl;     // 'C'
  cout << a.find("C") << endl; // 6

  int n = a.find("+++");
  cout << n << endl; // -1

  a.erase(1, 3);
  cout << a << endl; // "Ho C++!!"
}
