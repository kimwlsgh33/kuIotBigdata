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
  int pos = 0;
  // int pos = -1;
  // 'a' 가 몇번이 나올지, 횟수가 정해져있지 않다 (개발자가 알지 못한다)
  while (true) {
    // if (pos == 0) {
    //   pos = s.find('a', pos);
    // } else {
    //   pos = s.find('a', pos + 1);
    // }
    // pos = s.find('a', pos + 1);
    pos = s.find('a', pos);

    if (pos == -1)
      break;

    ++cnt;
    ++pos;
  }

  cout << "문자 a는 " << cnt << "개 있습니다." << endl;
}
