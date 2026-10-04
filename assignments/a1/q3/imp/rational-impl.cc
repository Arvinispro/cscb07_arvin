module rational;
import <iostream>;
import <fstream>;
import <sstream>;
import <iomanip>;
import <string>;

void Rational::simplify(){
  int num = this -> num;
  int dom = this -> dom;
  bool check = true;
  int PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199 };
  while(check){
    for(int i: PRIMES){
      if!(num%i || dom%i ){
        num = num/i;
        dom = dom/i;
        break;
      }
      if(i==199) check=false;
    }
  }
  this -> num = num;
  this -> dom = dom;
  std::cout << num << ' ' << dom << std::endl;
}