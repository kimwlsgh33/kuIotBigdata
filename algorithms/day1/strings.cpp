#include <cctype>
#include <iostream>

int main() {
  // getline + empty
  std::string content;
  std::string pracLine;

  std::cout << "Enter text: " << std::endl;

  do {
    getline(std::cin, pracLine);
    content += pracLine + "\n";
    // content.append(pracLine);
  } while (!pracLine.empty());

  std::cout << "New line: " << content << std::endl;

  // elements
  std::string eleStr = "abcdefg";
  eleStr.at(2);   // index
  eleStr[0];      // first
  eleStr.front(); // first
  eleStr.back();  // last

  // size, access - find character
  std::string str = "abcabcabc";
  // 강경 포문
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == 'c') {
      std::cout << "index of c: " << i << std::endl;
    }
  }

  // modifiers
  std::string addStr = "abc";
  addStr += "def";
  addStr.append("def");
  addStr.push_back('d');
  addStr.insert(0, "de"); // index
  std::cout << "addStr: " << addStr << std::endl;

  // remove
  std::string eraseStr = " An example sentence";
  eraseStr.erase(2, 8); // from index 2, remove 8
  eraseStr.erase(eraseStr.begin() + 1);

  std::string popStr = "boxes";
  popStr.pop_back(); // 뒤에서 몇개 지우기
  popStr.pop_back();

  // replace
  std::string replaceStr = "this is a test string";
  replaceStr.replace(9, 5, "n example"); // you don't have to care the length!
  std::cout << "replaceStr: " << replaceStr << std::endl;

  // find
  // TODO: draw
  std::string findStr("this is a test string. test2");
  std::string finder("test");
  std::size_t found = findStr.find(finder);

  if (found != std::string::npos)
    std::cout << "found at: " << found << std::endl;

  found = findStr.find(finder, found + finder.size() + 1);

  // substr - size of string
  std::string str2 = str.substr(2, 4);
  // idx -> size: last - first + 1

  // capitalize - in C, - subtracting 'A'... too
  std::string str3 = "abcDEF";
  for (int i = 0; i < str3.size(); ++i) {
    // str[i] = toupper(str[i]);
    if (isupper(str[i])) {
      str[i] = tolower(str[i]);
    }
    std::cout << str[i] << std::endl;
  }

  // 대소문자
  std::string compStr1 = "apple";
  std::string compStr2 = "banana";

  std::string input;
  std::cin >> input;
  // 일괄 변경
  for (int i = 0; i < input.size(); ++i) {
    if (isupper(input[i]))
      input[i] = tolower(input[i]);
  }

  if (input == compStr1)
    std::cout << "red" << std::endl;
  else if (input == compStr2)
    std::cout << "yellow" << std::endl;
  else
    std::cout << "unknown" << std::endl;
}
