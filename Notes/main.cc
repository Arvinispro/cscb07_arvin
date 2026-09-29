//client code(main.cc)
import point;
#include <iostream>

int main(){
  Point p(1,2);
  std::cout << p<<std::endl;
  p = p+p;
  std::cout << p<<std::endl;
}