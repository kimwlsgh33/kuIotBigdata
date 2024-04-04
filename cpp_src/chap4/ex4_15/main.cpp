#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cout << "여러줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다" << endl;
  getline(cin, s, '&');
  cin.ignore(); // remove '&' in the end.

  // get strings
  string f, r;
  cout << endl << "find: ";
  getline(cin, f, '\n');
  cout << "replace: ";
  getline(cin, r, '\n');

  int startIndex = 0;
  while (true) {
    // idx or -1
    int fIndex = s.find(f, startIndex);
    if (fIndex == -1)
      break;
    s.replace(fIndex, f.length(), r);
  }
  cout << s << endl;
}
