import rational;
import <iostream>;

int main(){
  int a = 48313;
  int b = 381;
  Rational r{a, b};
  std::cout << r.num << ' ' << r.den << std::endl;
  r.simplify();
  std::cout << r.num << ' ' << r.den << std::endl;
  return 0;
}