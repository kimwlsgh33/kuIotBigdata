#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cout << "7+23+5+100+25와 같이 덧셈 문자열을 입력하세요." << endl;
  getline(cin, s, '\n');
  // accumulator
  int sum = 0;
  int startIndex = 0;

  while (true) {
    // find '+' from s[startIndex]
    // found: first index, not found: -1
    int fIndex = s.find('+', startIndex);

    if (fIndex == -1) { // if doesn't found
      // part: [startIndex, last]
      string part = s.substr(startIndex);
      if (part == "") // if startIndex == last
        break;        // end
      cout << part << endl;
      sum += stoi(part);
      break;
    }
    // calc count of target number string
    int count = fIndex - startIndex;
    // part: [startIndex, count]
    string part = s.substr(startIndex, count);

    cout << part << endl;
    sum += stoi(part);
    // change start index into next number
    startIndex = fIndex + 1;
  }

  cout << "숫자들의 합은 " << sum;
}
