#include <iostream>
#include <string>
#include <sstream>

int main(){
  std::string f, f_line, f_word, f_big, f_small;
  int biggest=-1, smallest=1e10, count;
  // for each line
    while(! std::cin.eof()){
      count = 0;
      std::getline(std::cin, f_line);
      while(f_line >> f_word){
        count++;
      }
      if(count > biggest){
        f_big = f_line;
        biggest = count;
      }
      if(count < smallest){
        f_small = f_line;
        smallest = count;
      }
    }
    return 0;

}