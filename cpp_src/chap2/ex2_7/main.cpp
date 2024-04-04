#include <iostream>
#include <string>

using namespace std;

int main(void) {
  // you can have any size of string by `string` class!
  string song("Falling in love with you");
  string elvis("Elvis Presley");
  string jinho("김진호");
  string singer;

  // string concatenation by `+`
  cout << song + "을 부른 가수는";
  cout << "(힌트 :  첫글자는)" << elvis[0] << ")?";

  getline(cin, singer);
  // you can compare string by `=`
  if (singer == elvis)
    cout << "correct!";
  else
    cout << "you missed.. " + elvis << endl;
}
