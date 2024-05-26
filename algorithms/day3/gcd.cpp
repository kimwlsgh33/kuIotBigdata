#include <algorithm>
#include <iostream>

/*
 * @brief greatest common divisor
 * @param a, b
 * @return gcd
 * @details The GCD of two numbers is the largest integer that divides both of
 * them without leaving a remainder
 */
int get_gcd_my(int a, int b) {
  for (int i = a; i >= 1; --i) {
    if (a % i == 0 && b % i == 0)
      return i;
  }

  return 0;
}

int get_gcd(int a, int b) {
  int res = std::min(a, b);

  // NOTE: ==, != 이 >,  <  보다 연산이 빠르다
  while (res != 0) {
    if (a % res == 0 && b % res == 0)
      break;
    --res;
  }

  return res;
}

// euclidean algorithm
// 큰수를 두수의  차이로 교체
// a,b. a > b.    a -> (a-b) = c.    a, b, c
int get_gcd_euc(int a, int b) {
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  if (a == 1 || b == 1)
    return 1;
  if (a == b)
    return a;
  if (a > b)
    return get_gcd_euc(a - b, b);
  else
    return get_gcd_euc(b - a, b);
}

/*
 * @brief least common multiple
 * LCM (두수의 곱을 최대공약수로 나누면 최소공배수)
 * */
int get_lcm(int a, int b) {
  return (a * b) / get_gcd_euc(a, b);
}

int main() {
  std::string a, b;
  int num1, num2;

  while (true) {

    // input
    // std::cin >> num1 >> num2;
    std::getline(std::cin, a);
    std::getline(std::cin, b);
    // convert
    try {
      num1 = std::stoi(a);
      num2 = std::stoi(b);
      break;
    } catch (std::exception &e) {
      std::cout << "failure due to: " << e.what() << std::endl;
    }
  }

  int gcd = get_gcd(num1, num2);
  // output
  std::cout << num1 << num2 << gcd << std::endl;

}
