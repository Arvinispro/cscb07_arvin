import rational;
import <iostream>;

int main(){
  int a = 2994;
  int b = 1902;
  Rational r{a, b};
  std::cout << r.num << ' ' << r.den << std::endl;
  r.simplify();
  std::cout << r.num << ' ' << r.den << std::endl;
  return 0;
}