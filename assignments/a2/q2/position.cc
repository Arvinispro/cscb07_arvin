export module position;
import <iostream>;

export class Position {
  int ew, ns;
 public:
  Position(int ew = 0, int ns = 0);

  // Adds rhs.ew to this position's ew and
  // rhs.ns to this position's ns
  Position &operator+=(const Position &rhs);

  // Subtracts rhs.ew from this position's ew and
  // rhs.ns from this position's ns
  Position &operator-=(const Position &rhs);

  int getEW() const;
  int getNS() const;
  
  // Calculates the Manhattan distance of the this position to the origin
  // (the absolute north-south displacement plus the absolute east-west displacement)
  int manhattanDistance() const;
};

// Prints the current values of the position to out in the format:
// (ew,ns)
export std::ostream &operator<<(std::ostream &out, const Position &pos);
