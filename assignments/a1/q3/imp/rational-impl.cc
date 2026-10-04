module rational;
import <iostream>;
std::ostream &operator<<(std::ostream &out, const Rational &rat){
  if (rat.den==1){
    out << rat.num;
    return out;
  }
  if (rat.isZero()){
    out << 0;
    return out;
  }
  out << rat.num << '/' << rat.den;
  return out;
}
std::istream &operator>>(std::istream &in, Rational &rat){
  int NUM, DEN;
  in >> NUM;
  char slash;
  in >> slash;
  in >> DEN;
  Rational rsl(NUM, DEN);
  rat = rsl;
  return in;
}
Rational::Rational(int num, int den){

  if((num > 0 && den >0) || (num < 0 && den > 0)){
    this -> num = num;
    this -> den = den;
  }
  else{
    this -> num = -1 * num;
    this -> den = -1 * den;
  }
  this -> simplify();
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

Rational Rational::operator+(const Rational &rhs)const{ //start by learning this
  int NUM = (this -> num * rhs.den) + (rhs.num * this -> den);
  int DEN = (this -> den * rhs.den);
  Rational rsl{NUM, DEN};
  // rsl.simplify();
  return rsl;
}
Rational Rational::operator-(const Rational &rhs) const{
  int NUM = (this -> num * rhs.den) - (rhs.num * this -> den);
  int DEN = (this -> den * rhs.den);
  Rational rsl{NUM, DEN};
  // rsl.simplify();
  return rsl;
}
Rational Rational::operator*(const Rational &rhs) const{
  int NUM = this -> num * rhs.num;
  int DEN = this -> den * rhs.den;
  Rational rsl{NUM, DEN};
  // rsl.simplify();
  return rsl;
}
Rational Rational::operator/(const Rational &rhs) const{
  int NUM = this -> num * rhs.den;
  int DEN = this -> den * rhs.num;
  Rational rsl{NUM, DEN};
  // rsl.simplify();
  return rsl;
}

Rational& Rational::operator+=(const Rational &rhs){
  int NUM = (this -> num * rhs.den) + (rhs.num * this -> den);
  int DEN = (this -> den * rhs.den);
  this -> num = NUM;
  this -> den = DEN;
  this -> simplify();
  return *this;
}
Rational &Rational::operator-=(const Rational &rhs){
  int NUM = (this -> num * rhs.den) - (rhs.num * this -> den);
  int DEN = (this -> den * rhs.den);
  this -> num = NUM;
  this -> den = DEN;
  this -> simplify();
  return *this;
}
Rational Rational::operator-() const{
  int NUM = -1 * this -> num;
  int DEN = this -> den;
  Rational rsl(NUM, DEN);
  return rsl;
}

int Rational::getNumerator() const{
  return this -> num;
}
int Rational::getDenominator() const{
  return this -> den;
}
bool Rational::isZero() const{
  return this -> num == 0;
}