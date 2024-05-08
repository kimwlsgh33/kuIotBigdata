#include <iostream>
#include <stdlib.h>
#include <string>

void print_str(std::string *str, std::size_t begin, std::size_t length);
int isOvf(std::size_t idx, std::size_t len);

int main() {
  // api -> we can't know client's data
  // std::cout << "Please separate using \"\\n\"." << std::endl;
  std::string str = "This is a test string. test2";
  std::string finder = "test";

  std::size_t found = str.find(finder);

  while (found != std::string::npos) {
    std::cout << "Found: " << found << std::endl;

    // prevent overflow
    if (isOvf(found + finder.size(), str.size()))
      return -1;

    print_str(&str, found, finder.size());

    // HACK: What are differences between size() and length()?
    std::cout << "Find from: '" << str[found + finder.size()] << '\''
              << std::endl;
    // std::cout << "Or here: '" << str[found + finder.length()] << '\''
    //           << std::endl;
    found = str.find(finder, found + finder.size());
  }
}

void print_str(std::string *str, std::size_t begin, std::size_t length) {
  for (int i = 0; i < length; ++i) {
    std::cout << (*str)[begin + i];
  }
  std::cout << std::endl;
}

int isOvf(std::size_t idx, std::size_t len) {
  if (idx < len)
    return 0;

  std::cout << "Buffer Overflow" << std::endl;
  return 1;
}
