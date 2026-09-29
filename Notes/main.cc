//client code(main.cc)
#include <iostream>
import point;

int main(){
  Point p(1,2);
  std::cout << p.x<<std::endl;
  p = p+p;
  std::cout << p.x<<std::endl;
}