#include <iostream>
#include <string>
#include <sstream>

int main(){
  std::string f, f_line, f_word, f_big, f_small;
  int biggest=-1, smallest=2147483647, count;
  // for each line
    while(!std::cin.eof()){
      count = 0;
      std::getline(std::cin, f_line);
      std::istringstream f{f_line};
      // std::cout << f_line << std::endl;
      while(f >> f_word){
        count++;
      }
      // std::cout << count << std::endl;
      if(count > biggest){
        f_big = f_line;
        biggest = count;
      }
      if(count < smallest){
        f_small = f_line;
        smallest = count;
      }
      std::cout << smallest << std::endl;
    }
    std::cout << f_small << std::endl << f_big << std::endl;
    return 0;

}