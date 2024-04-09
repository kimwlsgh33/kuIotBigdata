#include <iostream>
using namespace std;

// int add(int (&a)[5], int num){
//   cout << a << endl;
//   int sum = 0;
//   for(int i = 0; i < num; ++i) {
//     sum += a[i];
//   }
//   return sum;
// }

int add(int (&a)[5], int num, int b[5] = 0){
  cout << a << ' ' << b << endl;
  int sum = 0;
  for(int i = 0; i < num; ++i) {
    sum += a[i] + b[i];
  }
  return sum;
}

int main() {
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {6, 7, 8, 9, 10};
  cout << a << ' ' << b << endl;
  int c = add(a, 5);
  int d = add(a, 5, b);
  cout << c << endl;
  cout << d << endl;
}
