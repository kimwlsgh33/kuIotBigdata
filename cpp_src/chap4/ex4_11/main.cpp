#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  string address("서울시 성북구 삼선동 389");
  string copyAddress(address);

  char text[] = "Love C++";
  string title(text);

  cout << str << endl;
  cout << address << endl;
  cout << copyAddress << endl;
  cout << title << endl;
}
