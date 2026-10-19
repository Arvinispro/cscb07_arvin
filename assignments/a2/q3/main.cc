import <iostream>;
import <string>;
import controller;
using namespace std;

int main() {
    Controller ctr;
    string cmd;
    string name, other;
    int x, y;
    char c;
    while (cin >> cmd) {
        if (cmd == "new") { // tests Canvas(int, int, char)
            cin >> name >> x >> y >> c;  // here, x is the width and y is the height
            ctr.create(name, x, y, c);
        } else if (cmd == "copy") { // tests the copy constructor and the copy assignment operator
            cin >> name >> other;
            ctr.copy(name, other);
        } else if (cmd == "move") { // tests the move constructor and the move assignment operator
            cin >> name >> other;
            ctr.move(name, other);
        } else if (cmd == "set") { // tests Canvas::set
            cin >> name >> x >> y >> c;
            ctr.set(name, x, y, c);
        } else if (cmd == "get") { // tests Canvas::get
            cin >> name >> x >> y;
            ctr.get(name, x, y);
        } else if (cmd == "fill") { // tests Canvas::fill
            cin >> name >> c;
            ctr.fill(name, c);
        } else if (cmd == "print") { // tests Canvas::print
            cin >> name;
            ctr.print(name);
        } else if (cmd == "size") { // tests Canvas::getWidth, getHeight, and isEmpty
            cin >> name;
            ctr.size(name);
        } else if (cmd == "delete") { // tests the destructor
            cin >> name;
            ctr.deleteCanvas(name);
        } else if (cmd == "quit") {
            break;
        } else {
            cerr << "Invalid command." << endl;
        }
    }
}
