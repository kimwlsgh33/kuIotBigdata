#ifndef EXP_H
#define EXP_H
// class(개념) -> objects(실체)
class Exp {
  // member variable declaration (선언 -  존재유무)
  int base, exponent;

public:
  // constructor declaration (선언 -  존재유무)
  Exp();
  Exp(int bs);
  Exp(int bs, int exp);

  // member function declaration (선언 - 존재유무)
  int getValue();
  int getBase();
  int getExp();
  bool equals(Exp exp_obj);
};
#endif
