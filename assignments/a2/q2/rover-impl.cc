module rover;
import <iostream>;
import <string>;

Rover::Rover(): dir{0} {}
Rover::~Rover(){} //default destructor is enough

void Rover::forward(int steps = 1){

  if (steps>0){
    switch(this->dir){
      case 0:
        Position temp{steps, 0};
      case 2:
        Position temp{-1*steps, 0};
      case 1:
        Position temp{0, steps};
      case 3:
        Position temp{0, -1*steps};
      this -> cur += temp;
      }
    this -> cur += temp;
    this -> numSteps += steps;
    
  }
}

void Rover::backward(int steps = 1){
  if (steps>0){
    switch(this->dir){
      case 0:
        Position temp{-1*steps, 0};
      case 2:
        Position temp{steps, 0};
      case 1:
        Position temp{0, -1*steps};
      case 3:
        Position temp{0, steps};
      this -> cur += temp;
    }
    this -> numSteps += steps;
    
  }
}

void Rover::left(){
  this -> dir--;
  this -> dir = this -> dir % 4;
}

void Rover::right(){
  this -> dir++;
  this -> dir = this -> dir % 4;
}

Position Rover::current() const{
  return this -> cur;
}

int Rover::irection() const{
  return this -> dir;
}

int Rover::totalDistance() const{
  return this -> numSteps;
}

int Rover::manhattanDistance() const{
  return {this->cur.manhattanDistance()};
}

std::ostream &operator<<(std::ostream &out, const Rover &rover){
  std::string direction;
  switch(rover.direction()){
    case(0):
      direction = "North";
      break;
    case(1):
      direction = "East";
      break;
    case(2):
      direction = "South";
      break;
    case(3):
      direction = "West";
      break;
  }
  out << "Current position: " << rover.current() << ", Facing " << direction;
  return out;
}