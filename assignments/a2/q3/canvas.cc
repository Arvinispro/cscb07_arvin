export module canvas;
import <iostream>;

export class Canvas {
    int width;    // number of columns (0 if the canvas is empty)
    int height;   // number of rows (0 if the canvas is empty)
    char **rows;  // array of height pointers; rows[y] points to an array of width
                  // characters (nullptr if the canvas is empty)
  public:
    // Creates a canvas with the given width and height, with every
    // pixel set to ch.
    Canvas(int width, int height, char ch = '.');

    // Copy constructor
    Canvas(const Canvas &other);
    // Move constructor
    Canvas(Canvas &&other);
    // Copy assignment operator
    Canvas &operator=(const Canvas &other);
    // Move assignment operator
    Canvas &operator=(Canvas &&other);
    // Destructor
    ~Canvas();

    // Returns the number of columns (0 if the canvas is empty)
    int getWidth() const;
    // Returns the number of rows (0 if the canvas is empty)
    int getHeight() const;
    // Returns true if the canvas is empty (it has no pixels).
    // A canvas is empty only after its contents have been moved to another canvas.
    bool isEmpty() const;

    // Returns the pixel at column x and row y.
    // (0,0) is the top-left pixel; x must be in [0, width) and y in [0, height).
    char get(int x, int y) const;
    // Sets the pixel at column x and row y to ch (same ranges as get)
    void set(int x, int y, char ch);
    // Sets every pixel of the canvas to ch (does nothing if the canvas is empty)
    void fill(char ch);

    // Prints the canvas to out. For a non-empty canvas, the output is a frame
    // around the rows of pixels, each line ending with a newline. For example,
    // a 4x2 canvas filled with dots is printed as:
    // +----+
    // |....|
    // |....|
    // +----+
    // An empty canvas is printed as the line:
    // (empty)
    void print(std::ostream &out) const;
};

// Prints the canvas to out by calling its print() method
export std::ostream &operator<<(std::ostream &out, const Canvas &canvas);
