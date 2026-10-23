module rover;
import <iostream>;

Rover::Rover(): dir{0} {}
Rover::~Rover(){} //default destructor is enough

void Rover::forward(int steps = 1){
  if (steps>0){
    switch(this->dir){
      case(0):
        this -> cur.ns += steps;
       break;
      case(2):
        this -> cur.ns -= steps;
       break;
      case(1):
        this -> cur.ew += steps;
       break;
      case(3):
        this -> cur.ew -= steps;
       break;
    }
    this -> numSteps += steps;
    
  }
}

void Rover::backward(int steps = 1){
  if (steps>0){
    switch(this->dir){
      case(0):
        this -> cur.ns -= steps;
       break;
      case(2):
        this -> cur.ns += steps;
       break;
      case(1):
        this -> cur.ew -= steps;
       break;
      case(3):
        this -> cur.ew += steps;
       break;
    }
    this -> numSteps += steps;
    
  }
}

void Rover::left(){
  this -> dir = --this->dir % 4;
}

void Rover::right(){
  this -> dir = ++this->dir % 4;
}

Position Rover::current() const{
  return this -> curr;
}

int direction() const{
  return this -> dir;
}

int totalDistance() const{
  return this -> numSteps;
}

int manhattanDistance() const{
  return {this->curr.manhattanDistance()}
}

std::ostream &operator<<(std::ostream &out, const Rover &rover){
  std::string direction;
  switch(rover.dir){
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
  out << "Current position: " << rover.curr << ", Facing " << direction;
  return out;
}