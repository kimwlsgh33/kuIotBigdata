#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
  // 3 자리 숫자
  char buf[16], tmp[16], op, left[4], right[4];
  int idx, cnt;
  int nLeft, nRight;

  while (true) {
    idx = 0;
    cnt = 0;

    cout << "? ";
    // input ascii string
    cin.getline(buf, sizeof(buf), '\n');

    while (buf[idx] != '\0') {
      if (buf[idx] == ' ') {
        if (cnt == 0) {
          // copy counter ~ '\0'
          strcpy(tmp, buf);
          tmp[idx] = '\0';
          // assign left until buf[counter]
          strcpy(left, tmp);
        } else {
          // assign operator
          op = buf[idx - 1];

          // assign right until buf[counter]
          strcpy(right, &buf[idx + 1]);
        }
        cnt++;
      }
      idx++;
    }

    // ascii to integer
    nLeft = atoi(left);
    nRight = atoi(right);

    switch (op) {
    case '+':
      cout << left << " + " << right << " = " << nLeft + nRight;
      break;
    case '-':
      cout << left << " - " << right << " = " << nLeft - nRight;
      break;
    case '*':
      cout << left << " * " << right << " = " << nLeft * nRight;
      break;
    case '/':
      cout << left << " / " << right << " = " << nLeft / nRight;
      break;
    case '%':
      cout << left << " % " << right << " = " << nLeft % nRight;
      break;
    default:
      cout << "default";
      break;
    }
    cout << '\n';
  }

  return 0;
}
