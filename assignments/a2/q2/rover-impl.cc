module rover;
import <iostream>;
import <string>;

Rover::Rover(): dir{0}, numSteps{0} {}
Rover::~Rover(){} //default destructor is enough

void Rover::forward(int steps){
  int x, y;
  if (steps>0){
    switch(this->dir){
      case 0:
        x = steps, y = 0;
        break;
      case 2:
        x = -1*steps, y = 0;
        break;
      case 1:
        x = 0, y = steps;
        break;
      case 3:
        x = 0, y = -1*steps;
        break;
    }
    Position temp{y, x};
    this -> cur += temp;
    this -> numSteps += steps;
  }
}

void Rover::backward(int steps){
  int x, y;
  if (steps>0){
    switch(this->dir){
      case 0:
        x = -1*steps, y = 0;
        break;
      case 2:
        x = steps, y = 0;
        break;
      case 1:
        x = 0, y = -1*steps;
        break;
      case 3:
        x = 0, y = steps;
        break;
    }
    Position temp{y, x};
    this -> cur += temp;
    this -> numSteps += steps;
  }
}

void Rover::left(){
  this -> dir--;
  if (this -> dir == -1) this -> dir = 3;
  // std::cout << this->dir << std::endl;
}

void Rover::right(){
  this -> dir++;
  this -> dir = this -> dir % 4;
}

Position Rover::current() const{
  return this -> cur;
}

int Rover::direction() const{
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