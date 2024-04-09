#include <iostream>
#include <string>
using namespace std;

class Book {
  string title;
  string author;
  int price;
  int pages;

public:
  Book(const string title, int price);
  Book(int price, const string title); // constructor overloading
  Book(const string title, const string author, int price, int pages);
  Book(const Book &other);
  ~Book();
  void set(const string title, int price);
  void set(const string title, const string author, int price, int pages);
  void show() {
    cout << title << ' ' << price << "WON" << endl;
    cout << author << ' ' << "p" << pages << endl;
  }
};

Book::Book(const string title, int price) {
  this->title = title;
  this->price = price;
}

Book::Book(const string title, const string author, int price, int pages) {
  this->title = title;
  this->author = author;
  this->price = price;
  this->pages = pages;
}

Book::Book(const Book &other) {
  // we don't have memory in `this->title`
  title = other.title;
  author = other.author;
  price = other.price;
  pages = other.pages;
}

Book::~Book() {}

void Book::set(const string title, int price) {
  this->title = title;
  this->price = price;
}

void Book::set(const string title, const string author, int price, int pages) {
  this->title = title;
  this->author = author;
  this->price = price;
  this->pages = pages;
}

int main() {
  Book cpp("명품C++", "황기태", 10000, 696);
  Book java = cpp; // copied!
  java.set("명품자바", "홍길동", 12000, 100);
  cpp.show();
  java.show();
}
