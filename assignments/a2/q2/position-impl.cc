module position;
import <iostream>;

// Position::Position(int ew = 0, int ns = 0): ew{ew}, ns{ns} {}

int Position::getEW() const{
  return {this->ew};
}

int Position::getNS() const{
  return {this->ns};
}

int Position::manhattanDistance() const{
  int ew = this->getEW(), ns = this->getNS();
  if( ew < 0 ) ew = -1 * ew;
  if( ns < 0 ) ns = -1 * ns;

  return {ns + ew};
}

Position &operator+=(const Position &rhs){
  this -> ew = this -> getEW() + rhs.getEW();
  this -> ns = this -> getNS() + rhs.ns;
  return *this;
}

Position &operator-=(const Position &rhs){
  this -> ew = this -> getEW() - rhs.getEW();
  this -> ns = this -> getNS() - rhs.ns;
  return *this;
}

std::ostream &operator<<(std::ostream &out, const Position &pos){
  out << "(" << pos.getEW() << "," << pos.getNS() << ")";
  return out;
}
