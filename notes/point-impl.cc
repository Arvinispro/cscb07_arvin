//implementation (porint-impl.cc)
module point; //this file is part of the module, and it implicitly imports the interface

Point operator+(const Point &p1, const Point &p2){
  return {p1.x+p2.x, p1.y+p2.y};
}

