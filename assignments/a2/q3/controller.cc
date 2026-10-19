export module controller;
import <iostream>;
import <string>;
import canvas;

export class Controller {
    static constexpr int NUM_CANVASES = 4;
    Canvas *canvases[NUM_CANVASES];  // the canvases called A to D (nullptr if the canvas does not exist)
    int slot(const std::string &name) const;      // returns the slot of the canvas called name, or -1 if the name is not valid
    int existing(const std::string &name) const;  // returns the slot of the canvas called name, or -1 if it does not exist
  public:
    Controller();
    ~Controller();
    void create(const std::string &name, int w, int h, char c);  // tests Canvas(int, int, char)
    void copy(const std::string &from, const std::string &to);   // tests the copy constructor and the copy assignment operator
    void move(const std::string &from, const std::string &to);   // tests the move constructor and the move assignment operator
    void set(const std::string &name, int x, int y, char c);     // tests Canvas::set
    void get(const std::string &name, int x, int y);             // tests Canvas::get
    void fill(const std::string &name, char c);                  // tests Canvas::fill
    void print(const std::string &name);                         // tests Canvas::print
    void size(const std::string &name);                          // tests Canvas::getWidth, getHeight, and isEmpty
    void deleteCanvas(const std::string &name);                  // tests the destructor
};
