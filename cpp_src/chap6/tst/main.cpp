#include <iostream>
using namespace std;

int sum(int a, int b = 20, int c = 30) {
  return a + b + c;
}

int main() {
  int result = 0;

  result = sum(10);
  cout << "Result : " << result << endl;
  result = sum(10, 20);
  cout << "Result : " << result << endl;
  result = sum(10, 20, 30);
  cout << "Result : " << result << endl;
}
