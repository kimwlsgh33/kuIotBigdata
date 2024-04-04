#include "Date.h"
#include <iostream>
#include <sstream> // string streaming
#include <string>
#include <vector> // vector container

// brings all the symbols from the `std` namespace into the current namespace.
using namespace std;
vector<string> Date::split(string input, char delimiter) {
  // read string like a stream
  istringstream iss(input);
  string token;
  vector<string> tokens;

  while (getline(iss, token, delimiter)) {
    tokens.push_back(token);
  }

  return tokens;
}

// convert std::string -> string by using namespace
Date::Date(int y, int m, int d) {
  year = y;
  month = m;
  day = d;
} // 1
Date::Date(string str_ymd) {
  // separate by '/'
  // string to integer -> stoi()
  vector<string> result = split(str_ymd, '/');

  year = stoi(result[0]);
  month = stoi(result[1]);
  day = stoi(result[2]);
} // 2
void Date::show() {
  cout << year << "년" << month << "월" << day << "일" << endl;
} // 3

int Date::getYear() { return year; }   // 4 - 1
int Date::getMonth() { return month; } // 4 - 2
int Date::getDay() { return day; }     // 4 - 3
