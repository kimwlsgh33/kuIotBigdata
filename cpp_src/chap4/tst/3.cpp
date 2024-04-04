#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "문자열 입력>> ";
  string s;
  getline(cin, s, '\n');

  int cnt = 0;
  //==(1)==
  // for (int i = 0; i < s.length(); ++i) {
  //   if (s.at(i) == 'a') {
  //     ++cnt;
  //   }
  // }

  //==(2)==
  int startIndex = 0;
  while (startIndex != -1) {
    startIndex = s.find('a', startIndex);
    ++cnt;
  }

  cout << "문자 a는 " << cnt << "개 있습니다." << endl;
}
