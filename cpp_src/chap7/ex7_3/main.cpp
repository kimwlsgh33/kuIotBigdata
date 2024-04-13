#include <iostream>
using namespace std;

class RectManager;
class Rect {
  int width, height;
  friend RectManager;

public:
  Rect(int width, int height) {
    this->width = width;
    this->height = height;
  };
};

class RectManager {
public:
  bool equals(Rect r, Rect s);
  void copy(Rect &dest, Rect &src);
};

bool RectManager::equals(Rect r, Rect s) {
  if (r.width == s.width && r.height == s.height)
    return true;
  return false;
}

void RectManager::copy(Rect &dest, Rect &src) {
  dest.width = src.width;
  dest.height = src.height;
}

int main() {
  Rect a(3, 4), b(5, 6);
  RectManager man;

  man.copy(b, a);
  if (man.equals(a, b))
    cout << "equal" << endl;
  else
    cout << "not equal" << endl;
}
