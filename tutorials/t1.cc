#include <iostream>
#include <sstream>

int main() {
  // int x, y, z;
  // std::cin >> x >> y >> z;
  // if cin=245 623 243, cout=245. If cin =    12, cout=12
  // std::cout << x << y << z;
  
  // istringstream > input/read
  // ostringstream > write

  std::string xs;
  int n, sum;
  std::getline(std::cin, xs);//will give us the entire line
  while (true){
    if(std::istringstream iss{xs}; iss >> n) sum += n else break;
  }

  std::ifstream f{"input"};
  std::string y;
  while(f >> y){
    std::cout << y << std::endl;
  }
  
}

int main(int argc, char* argv[]){
  for(int i; i<argc; i++){
    std::string arg = argv[i];
    std::cout << arg << std::endl;
  }

  // ./a.out arg1 arg2
  // argc = 3, argv[0]=./a.out, argv[1] = arg1 ...
  return 0;
}