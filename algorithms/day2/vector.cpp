#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5}; // std::vector<int> v({1, 2, 3, 4, 5});

  std::cout << v.size() << std::endl;

  if (v.empty())
    std::cout << v.size() << std::endl;

  v.clear();

  std::vector<std::string> strVec = {"a", "b", "c"};
  strVec[0];
  // strVec.at(1);
  strVec.front();
  strVec.back();

  // 어떻게 구성을 짤지? - 알고리즘

  // access element
  std::vector<int> intVec = {1, 2, 3, 4, 5};
  for (int i = 0; i < strVec.size(); ++i) {
    std::cout << strVec.at(i) << std::endl;
  }

  // iterator: pointer - begin(), end()
  std::vector<std::string>::iterator strIt = strVec.begin();
  std::cout << *(strIt + 1) << std::endl;

  for (; strIt != strVec.end(); ++strIt) {
    std::cout << *strIt << std::endl;
  }

  // modifier
  std::vector<std::string> addVec{"ab", "cd"};
  addVec.push_back("ef");                  // "ab", "cd", "ef"
  addVec.insert(addVec.begin() + 1, "gh"); // "ab", "gh", "cd", "ef"

  // remove
  std::vector<int> rmVec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  rmVec.pop_back(); // 1 ~ 9
  rmVec.erase(rmVec.begin() + 2); // remove at index 2
  rmVec.erase(rmVec.begin() + 2, rmVec.begin() + 5); // remove from index 2 to 4
}
