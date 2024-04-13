#include <iostream>
using namespace std;

class Book {
  string title;
  int price, pages;
  friend bool operator<(const string &str, const Book &op2);

public:
  Book(string title = "", int price = 0, int pages = 0) {
    this->title = title;
    this->price = price;
    this->pages = pages;
  }
  void show() {
    cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
  }
  string getTitle() { return title; }
};

bool operator<(const string &str, const Book &op2) { return str < op2.title; }

int main() {
  Book a("청춘", 20000, 300);
  string b;
  cout << "책 이름을 입력하세요>>";
  getline(cin, b);
  // b.<(a)
  if (b < a)
    cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!" << endl;
}
