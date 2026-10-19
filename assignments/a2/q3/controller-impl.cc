module controller;
import <iostream>;
import <string>;
import <utility>;
import canvas;
using namespace std;

Controller::Controller(): canvases{} {}  // all the canvases start as nullptr

Controller::~Controller() {
    for (int i = 0; i < NUM_CANVASES; ++i) {
        delete canvases[i];
    }
}

int Controller::slot(const string &name) const {
    if (name.size() == 1 && name[0] >= 'A' && name[0] < 'A' + NUM_CANVASES) {
        return name[0] - 'A';
    }
    cerr << "Invalid canvas name." << endl;
    return -1;
}

int Controller::existing(const string &name) const {
    int i = slot(name);
    if (i >= 0 && canvases[i] == nullptr) {
        cerr << "Canvas " << name << " does not exist." << endl;
        return -1;
    }
    return i;
}

void Controller::create(const string &name, int w, int h, char c) {
    int i = slot(name);
    if (i < 0) return;
    if (canvases[i] != nullptr) {
        cerr << "Canvas " << name << " already exists." << endl;
    } else if (w <= 0 || h <= 0) {
        cerr << "Width and height must be positive." << endl;
    } else {
        canvases[i] = new Canvas{w, h, c};
        cout << "Canvas " << name << " created (" << w << "x" << h << ")." << endl;
    }
}

void Controller::copy(const string &from, const string &to) {
    int i = existing(from);
    if (i < 0) return;
    int j = slot(to);
    if (j < 0) return;
    if (canvases[j] == nullptr) {
        canvases[j] = new Canvas{*canvases[i]};  // using the copy constructor
    } else {
        *canvases[j] = *canvases[i];             // using the copy assignment operator
    }
    cout << "Canvas " << to << " is now a copy of canvas " << from << "." << endl;
}

void Controller::move(const string &from, const string &to) {
    int i = existing(from);
    if (i < 0) return;
    int j = slot(to);
    if (j < 0) return;
    if (canvases[j] == nullptr) {
        canvases[j] = new Canvas{std::move(*canvases[i])};  // using the move constructor
    } else {
        *canvases[j] = std::move(*canvases[i]);             // using the move assignment operator
    }
    cout << "Canvas " << from << " was moved to canvas " << to << "." << endl;
}

void Controller::set(const string &name, int x, int y, char c) {
    int i = existing(name);
    if (i < 0) return;
    if (x < 0 || x >= canvases[i]->getWidth() || y < 0 || y >= canvases[i]->getHeight()) {
        cerr << "Position (" << x << "," << y << ") is outside canvas " << name << "." << endl;
    } else {
        canvases[i]->set(x, y, c);
        cout << "Set (" << x << "," << y << ") of canvas " << name << " to '" << c << "'." << endl;
    }
}

void Controller::get(const string &name, int x, int y) {
    int i = existing(name);
    if (i < 0) return;
    if (x < 0 || x >= canvases[i]->getWidth() || y < 0 || y >= canvases[i]->getHeight()) {
        cerr << "Position (" << x << "," << y << ") is outside canvas " << name << "." << endl;
    } else {
        cout << "(" << x << "," << y << ") of canvas " << name << " is '"
             << canvases[i]->get(x, y) << "'." << endl;
    }
}

void Controller::fill(const string &name, char c) {
    int i = existing(name);
    if (i < 0) return;
    canvases[i]->fill(c);
    cout << "Canvas " << name << " filled with '" << c << "'." << endl;
}

void Controller::print(const string &name) {
    int i = existing(name);
    if (i < 0) return;
    cout << *canvases[i];
}

void Controller::size(const string &name) {
    int i = existing(name);
    if (i < 0) return;
    if (canvases[i]->isEmpty()) {
        cout << "Canvas " << name << " is empty." << endl;
    } else {
        cout << "Canvas " << name << " is " << canvases[i]->getWidth() << "x"
             << canvases[i]->getHeight() << "." << endl;
    }
}

void Controller::deleteCanvas(const string &name) {
    int i = existing(name);
    if (i < 0) return;
    delete canvases[i];
    canvases[i] = nullptr;
    cout << "Canvas " << name << " deleted." << endl;
}
