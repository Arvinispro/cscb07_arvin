import rational;
import <iostream>;

int main(){
  Rational r1, r2;
  std::cin >> r1;
  std::cin >> r2;
  Rational r = r1 + r2;
  std::cout << r << std::endl;
  // std::cout << r.num << ' ' << r.den << std::endl;
  return 0;
}