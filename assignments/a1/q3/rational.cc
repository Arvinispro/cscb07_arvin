export module rational;
import <iostream>;

export struct Rational {
  int num;
  int den;
  void simplify();

  Rational(int num = 0, int den = 1);
  Rational operator+(const Rational &rhs) const;
  Rational operator-(const Rational &rhs) const;
  Rational operator*(const Rational &rhs) const;
  Rational operator/(const Rational &rhs) const;
  
  Rational &operator+=(const Rational &rhs);
  Rational &operator-=(const Rational &rhs);
  Rational operator-() const;

  int getNumerator() const;
  int getDenominator() const;
  bool isZero() const;
};
export std::ostream &operator<<(std::ostream &out, const Rational &rat);
export std::istream &operator>>(std::istream &in, Rational &rat);
