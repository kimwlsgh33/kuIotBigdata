#include <cstdlib>
#include <iostream>
using namespace std;

int main(void) {
  char left[10], right[10], op;
  int iLeft, iRight;

  while (true) {
    cout << "? ";
    cin >> left >> op >> right;

    // ascii to integer
    iLeft = atoi(left);
    iRight = atoi(right);

    switch (op) {
    case '+':
      cout << left << " + " << right << " = " << iLeft + iRight;
      break;
    case '-':
      cout << left << " - " << right << " = " << iLeft - iRight;
      break;
    case '*':
      cout << left << " * " << right << " = " << iLeft * iRight;
      break;
    case '/':
      cout << left << " / " << right << " = " << iLeft / iRight;
      break;
    case '%':
      cout << left << " % " << right << " = " << iLeft % iRight;
      break;
    default:
      cout << "default";
      break;
    }

    // cout << "\n";
  }

  return 0;
}
