//interface(point.cc)
export module point; //indicate that this is the module interface file
export struct Point{
  int x, y;
};

export Point operator+(const Point &p1, const Point &p2);


