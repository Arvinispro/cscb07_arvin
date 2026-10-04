import rational;
import <iostream>;

int main(){
  int a = 2994;
  int b = 1902;
  int c = 293;
  int d = 1291;
  Rational r1{a, b};
  Rational r2{c, d};
  Rational r = r1 + r2;
  std::cout << r.num << ' ' << r.den << std::endl;
  // std::cout << r.num << ' ' << r.den << std::endl;
  return 0;
}