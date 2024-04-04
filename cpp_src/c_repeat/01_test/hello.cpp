#include <iostream>
// This file uses std namespace
using namespace std;

int main(void) {
  // std::cout << "Hello\n\r";
  // std::cout << "World\r\n";
  // cout << "Hello\n\r";
  // cout << "World\r\n";

  int width;
  int height;

  // cout << "너비를 입력하세요>>";
  // cin >> width; // 키보드로부터 정수 값 너비를 읽어 width 변수에 저장
  // cout << "높이를 입력하세요>>";
  // cin >> height;

  // 여러개의 값 입력받기 (내부적으로 포인터사용)
  cin >> height >> width;

  int area = width * height;
  cout << "면적은 " << area << "\n";
  return 0;
}
