// What should I do?
// input various base and exponent by object
// calculate exponent and print
int main(void) {
  Exp a(3, 2);
  // 1. Exp type? -> struct, class
  // 2. a(3, 2) -> constructor -> class!
  // 3. a : object(instance)!
  // we want to create object `a` by class `Exp`
  // constructor -> initilize member variable
  Exp b(9);
  Exp c;

  cout << a.getValue();
  // 1. a.getValue() -> `a` : object, `.` : member, `getValue()` : function
  // we want to calculate result of exponent
}
