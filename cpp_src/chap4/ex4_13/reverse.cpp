#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cout << "아래에 문자열을 입력하세요  빈 칸이 있어도 됩니다(한글 안됨)"
       << endl;
  getline(cin, s, '\n');
  int len = s.length();

  for (int i = 0; i < len; ++i) {
    string last = s.substr(len - 1, 1);
    string sub = s.substr(0, len - 1);
    // assign new string into `s`
    s = last + sub;
    cout << s << endl;
  }
}
