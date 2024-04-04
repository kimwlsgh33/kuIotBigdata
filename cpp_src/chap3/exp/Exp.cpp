#include "Exp.h"
// constructor definition (정의 -  기능)
Exp::Exp() : Exp(1) {}
Exp::Exp(int base) {
  this->base = base;
  exponent = 1;
}
Exp::Exp(int base, int exponent) {
  this->base = base;
  this->exponent = exponent;
}

// member functions definition (정의 -  기능 구현)
int Exp::getValue() {
  // base(3)를 exponent(2)번 곱한다
  // 결과값 저장용 변수
  int result = 1;
  // 반복횟수 정하기
  for (int i = 0; i < exponent; ++i) {
    result *= base;
  }

  return result;
}

int Exp::getBase() { return base; }
int Exp::getExp() { return exponent; }
bool Exp::equals(Exp exp_obj) { return getValue() == exp_obj.getValue(); }
