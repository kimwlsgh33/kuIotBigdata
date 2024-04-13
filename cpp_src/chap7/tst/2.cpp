#include <iostream>
using namespace std;

class BookManager;
class Book {
  string title;
  int price, pages;
  friend bool operator==(const Book &op1, int price);
  friend bool operator==(const Book &op1, string title);
  friend bool operator==(const Book &op1, const Book &book);

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
  // bool operator==(int price);
  // bool operator==(string title);
  // bool operator==(Book book);
};

bool operator==(const Book &op1, int price) { return op1.price == price; }
bool operator==(const Book &op1, string title) { return op1.title == title; }
bool operator==(const Book &op1, const Book &book) {
  return op1.title == book.title && op1.price == book.price &&
         op1.pages == book.pages;
}

// bool Book::operator==(int price) { return this->price == price; }
// bool Book::operator==(string title) {
//   return this->title == title;
// }
// bool Book::operator==(Book book) {
//   return title == book.title && price == book.price && pages == book.pages;
// }

int main() {
  Book a("명품 C++", 30000, 300), b("고품 C++", 30000, 500);
  if (a == 30000)
    cout << "정가 30000원" << endl;
  if (a == "명품 C++")
    cout << "명품 C++ 입니다." << endl;
  if (a == b)
    cout << "두 책이 같은 책입니다." << endl;
}
