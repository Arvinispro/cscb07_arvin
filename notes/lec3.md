// Constructor

struct Student{
  int assns, test, final;
  float grade();
  Student(int assns, int test, int final); // constructor

}

Student::Student(int assns, int test, int final){
  this -> assns (this is the field) = assns;
  this -> test = test;
  this -> final = final;
}

Student s{60, 70, 80}; //calls constructor

struct Student{
  Student(int assns = 0, int test = 0, int final = 0){
    this -> assns = assns;
    ...
  }
}
Student s2{70, 80} //works={70, 80, 0}
or
Student s = Student(60, 70, 80);


if no constructor(ctor) is defined -> C style field-by-field initialization
if a ctor is defined -> data value are passed as args to ctor
  - c style initialization is not available if ctor is defined

Heap allocation:
Student *p = new Student{60, 70, 80};
struct Point{
  int x, y;
};
Point p; // default coonstructor: doesn't do anything, x and y are indeterminate

struct Point{
  int x, y;

  Point(int x, int y){
    this -> x = x;
    this -> y = y;
  }
};
Point p; //this is not gonna work

struct Line{
  Point p1, p2;
}
Line l1; //won't work because default ctor is trying to default ctor all fields that are objects, p1 p2 have not default ctor

Line(){
  p1 = Point(1,0); // this will not solve the problem, at this moment, Point default ctor was already called
  p2 = Point(0,1); 
}

Object creation steps:
1. spaces allocated
2. fields constructed in declaration ( ctor run for fields that are objects )
3. ctor body runs

personal idea: Line(p1 = Point(1,0), p2 = Point(0,1)){}

Member Initialization Lists(MIL)
Student Student(int assns, int test, int final):
  assns{assns}, test{test}, final{final} //step 2
  {} //step 3

Line:: Line():p1{1,0}, p2{0,1} {}
More generally
Line(const Point &p1, const Point &p2): p1{p1}, p2{p2} {}

Fields are initialized in the order in which they were declared in the class even if MIL orders them differently

struct Line{
  Point p1 {1, 0}, p2 {0, 1} // if an MIL does not ention a field, these values will be used
  Line() {} //uses default values 
  Line(const Point &p1, const Point &p2): p1{p1}, p2{p2} {} //the reason for using const is because p1 and p2 might change, we want it fixed at this moment
}

MIL must be used:
- for fields that are objects with no default ctor
- for fields that are const or references