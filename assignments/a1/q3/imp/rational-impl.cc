module rational;
import <iostream>;
// std::ostream &operator<<(std::ostream &out, const Rational &rat){

// }
// std::istream &operator>>(std::istream &in, Rational &rat);{

// }
Rational::Rational(int num, int den){
  this -> num = num;
  this -> den = den;
}

void Rational::simplify(){
  int num = this -> num;
  int den = this -> den;
  bool check = true;
  int PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199 };
  while(check){
    for(int i: PRIMES){
      if(!(num%i || den%i )){
        num = num/i;
        den = den/i;
        break;
      }
      if(i==199) check=false;
    }
  }
  this -> num = num;
  this -> den = den;
}
Rational Rational::operator+(const Rational &rhs)const{
  int NUM = (this -> num * rhs.den) + (rhs.num * this -> den);
  int DEN = (this -> den * rhs.den);
  Rational rsl{NUM, DEN};
  rsl.simplify();
  return rsl;
}