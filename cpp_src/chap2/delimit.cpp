#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void) {
  // 3 자리 숫자
  char buf[16], tmp[16], op, left[4], right[4];
  int idx, isFirst;
  int nLeft, nRight;

  while (true) {
    idx = 0;
    isFirst = 1;

    cout << "? ";
    // input ascii string
    cin.getline(buf, sizeof(buf), '\n');

    if (strcmp(buf, "quit") == 0) {
      break;
    }

    while (buf[idx] != '\0' || idx < 16) {
      if (buf[idx] == ' ') {
        if (isFirst == 1) {
          // copy counter ~ '\0'
          strcpy(tmp, buf);
          tmp[idx] = '\0';
          // assign left until buf[counter]
          strcpy(left, tmp);
          isFirst = 0;
        } else {
          // assign operator
          op = buf[idx - 1];

          // assign right until buf[counter]
          strcpy(right, &buf[idx + 1]);
          // there is no ' ' after this
          break;
        }
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
      cout << "there is no operator" << op;
      break;
    }
    cout << '\n';
  }

  return 0;
}
