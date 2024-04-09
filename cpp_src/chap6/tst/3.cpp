#include <iostream>
using namespace std;

int big(int a, int b, int lim = 100){
  int large = a > b ? a : b;
  return large > lim ? lim : large;
}

int main() {
  int x = big(3, 5);
  int y = big(300, 60);
  int z = big(30, 60, 50);
  cout << x << ' ' << y << ' ' << z << endl;
}
