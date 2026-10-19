export module rover;
import <iostream>;
import position;

export class Rover {
  Position cur; // current position
  int dir;  // 0 = N, 1 = E, 2 = S, 3 = W
  int numSteps; // total number of steps travelled by the rover
 public:
  // Initializes a rover at the position (0,0), facing North
  Rover();
  ~Rover();
  
  // Moves the rover forward by the number of steps in the direction it is facing
  // steps must be a positive number
  void forward(int steps = 1);

  // Moves the rover backward by the number of steps, i.e., opposite to the
  // direction it is facing. The direction the rover is facing does not change.
  // steps must be a positive number
  void backward(int steps = 1);

  // Turns the rover 90 degrees left (counterclockwise) without moving it
  void left();

  // Turns the rover 90 degrees right (clockwise) without moving it
  void right();

  // Returns the current position  
  Position current() const;
  
  // Returns the direction the rover is facing: 0 = N, 1 = E, 2 = S, 3 = W
  int direction() const;
  
  // Returns the total number of steps travelled by the rover
  int totalDistance() const;
  
  // Returns the Manhattan distance of the current position to the origin
  int manhattanDistance() const;
};

// Prints the current status of the rover to out in the format:
// Current position: (ew,ns), Facing <direction>
// where <direction> is North, East, South, or West
export std::ostream &operator<<(std::ostream &out, const Rover &rover);
