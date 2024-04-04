/**
 * output:
 * 1945년8월15일  <- show()
 * 2014,3,20
 *
 * 2014 <- getYear()
 * 3    <- getMonth()
 * 20   <- getDay()
 */

#include <iostream>
using namespace std;

#include "Date.h"

int main() {
  Date birth(2014, 3, 20); // 1

  // birth.split("2024/10/31", '/');

  Date independenceDay("1945/8/15"); // 2
  independenceDay.show();            // 3
  cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay()
       << endl; // 4
}
