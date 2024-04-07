#include <iostream>
using namespace std;

void combine(const string &text1, const string &text2, string &dst) {
  dst = text1 + ' ' + text2;
}

int main() {
  string text1("I love you"), text2("very much");
  string text3;
  combine(text1, text2, text3);
  cout << text3;
}
