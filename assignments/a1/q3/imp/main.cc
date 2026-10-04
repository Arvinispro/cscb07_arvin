import rational;
import <iostream>;

int main(){
  int a = 20;
  int b = 50;
  Rational r{a, b};
  std::cout << r.num << ' ' << r.den << std::endl;
  r.simplify();
  std::cout << r.num << ' ' << r.den << std::endl;
  return 0;
}