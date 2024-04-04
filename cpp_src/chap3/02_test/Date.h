#ifndef DATE_H
#define DATE_H
#include <string>
#include <vector>

class Date {
private:
  std::vector<std::string> split(std::string input, char delimiter);
  int year, month, day;

public:
  Date(int year, int month, int day); // 1
  Date(std::string str_ymd);          // 2
  void show();                        // 3
  int getYear();                      // 4 - 1
  int getMonth();                     // 4 - 2
  int getDay();                       // 4 - 3
};
#endif
