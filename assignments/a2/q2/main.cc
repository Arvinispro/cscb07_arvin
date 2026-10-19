import <iostream>;
import <string>;
import rover;
using namespace std;

int main() {
  Rover rv;
  char c;
  int i;
  while (cin >> c) {
    switch(c) {
      case 'f':
        cin >> i;
        rv.forward(i);
        break;
      case 'b':
        cin >> i;
        rv.backward(i);
        break;
      case 'l':
        rv.left();
        break;
      case 'r':
        rv.right();
        break;
      case 'c':
        cout << rv << endl;
        break;
      case 't':
        cout << rv.totalDistance() << endl;
        break;
      case 'm':
        cout << rv.manhattanDistance() << endl;
        break;
    }
  }
}
