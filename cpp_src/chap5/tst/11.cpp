#include <cstring>
#include <iostream>
using namespace std;

class Book {
  char *title;
  char *author;
  int price;
  int pages;

public:
  Book(const char *title, int price);
  Book(const char *title, const char *author, int price, int pages);
  Book(const Book &other);
  ~Book();
  void set(const char *title, int price);
  void set(const char *title, const char *author, int price, int pages);
  void show() {
    cout << title << ' ' << price << "WON" << endl;
    cout << author << ' ' << "p" << pages << endl;
  }
};

Book::Book(const char *title, int price) {
  // we don't have memory in `this->title`
  int len = strlen(title);
  this->title = new char[len + 1];
  strcpy(this->title, title);

  this->price = price;
}

Book::Book(const char *title, const char *author, int price, int pages) {
  int len = strlen(title);
  this->title = new char[len + 1];
  strcpy(this->title, title);

  len = strlen(author);
  this->author = new char[len + 1];
  strcpy(this->author, author);

  this->price = price;
  this->pages = pages;
}

Book::Book(const Book &other) {
  // we don't have memory in `this->title`
  int len = strlen(other.title);
  title = new char[len + 1];
  strcpy(title, other.title);

  len = strlen(other.author);
  author = new char[len + 1];
  strcpy(author, other.author);

  price = other.price;
  pages = other.pages;
}

Book::~Book() {
  if (title)
    delete[] title;

  if (author)
    delete[] author;
}

void Book::set(const char *title, int price) {
  if (this->title)
    delete[] this->title;

  int len = strlen(title);
  this->title = new char[len + 1];
  strcpy(this->title, title);

  this->price = price;
}

void Book::set(const char *title, const char *author, int price, int pages) {
  if (this->title)
    delete[] this->title;
  if (this->author)
    delete[] this->author;

  int len = strlen(title);
  this->title = new char[len + 1];
  strcpy(this->title, title);

  len = strlen(author);
  this->author = new char[len + 1];
  strcpy(this->author, author);

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
