//implementation (point-impl.cc)

module point; //This file is part of the module point
	      //implicitly imports the interface

Point operator+(const Point &p1, const Point &p2) {
	return {p1.x + p2.x, p1.y + p2.y};
}
