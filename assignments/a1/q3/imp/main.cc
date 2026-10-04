import rational;
import <iostream>;

int main(){
  int a = 20;
  int b = 50;
  Rational r{a, b};
  std::cout << r << std::endl;
  r.simplify()
  std::cout << r << std::endl;
  return 0;
}