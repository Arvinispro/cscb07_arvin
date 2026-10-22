module calc;
import <iostream>;

std::ostream &operator<<(std::ostream &out, const Calc &c){
  if(c.memory == 0) out << c.display;
  else  out << c.display << " M: " << c.memory;
  if(c.error) out << " E";
  return out;
}

void Calc::digit(int digit){
  //Check digit
  if(digit>= 0 && digit <= 9){
    if (this -> display > 0) this -> display = this -> display * 10 + digit;

    else if( this -> display < 0) this -> display = this -> display * 10 - digit;
    else this -> display = digit;
  }
}

void Calc::op(char oper){
  if(this -> oper == 0){
    this -> result = this -> display;
  }
  else{
    if(this -> oper == '+'){
      this -> result = this -> result + display;
    }
    else if(this -> oper == '-'){
      this -> result = this -> result - display;
    }
    else if(this -> oper == '*'){
      this -> result = this -> result * display;
    }
    else if(this -> oper == '/'){
      if (this -> display == 0) {
        this -> result = 0;
        this -> error = this -> isError();
      }
      else this -> result = this -> result / display;
    }
  }
  this -> oper = oper;
  this -> display = 0;
}
void Calc::equals(){
  op(0);
  this -> result = this -> result;
  this -> display = this -> result;
}
bool Calc::isError() const{
  return true;
}

void Calc::memPlus(){
  this -> memory = this -> display + this -> result + this -> memory;
}

void Calc::memClear(){
  this -> memory = 0;
}

void Calc::memRecall(){
  this -> display = this -> memory;
}

void Calc::allClear(){
  this -> display = 0;
  this -> result = 0;
  this -> memory = 0;
  this -> oper = 0;
  this -> error = false;
}