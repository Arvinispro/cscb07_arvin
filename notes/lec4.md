Line::Line(const Point &p1, const Point &p2) : p1{p1}, p2{p2}, {}

Copy constructor: construction work by constructing an object as copy of another object
Student s{60, 70, 90};
Student s2 = s; // copy ctor

Every class comes with 
- default ctor
- copy ctor - copy all fields
- copy assignment operator
- destructor
- move ctor
- move assignment operator

struct Student {
  int assns, test, final;
  //...
  Student(const Student &other) : assns{other.assns}, test{other.test}, final{other.final} {}
}
The above is equavalent to the default copy ctor

Q: When do we wanna defiine our own copy ctor?
struct Node {
  int data;
  Node *node;
}

Node *n = new Node{1, new Node{2, new Node{3, nullptr}}};
What would happen if (shallow copy, only first node is copied)
Node m = *n; // m will store Node{1,  new Node{2, new Node{3, nullptr}}} in stack, the rest are pointed instead of a complete copy
Node *p = new Node{*n}; // p will store the pointer in copy, the first node in heap is copied, the rest are pointed again instead of being copied.

//the correct way (deep copy, copies the whole list. U must write own ctor)
struct Node {
  int data;
  Node *node;

  Node(const Node &other) : data{other.data}, next{other.next ? new Node{*other.next} : nullptr} {}
}
conditional operator:
conditiona ? expression1 : expression2
            condition=true : condition=false

Copy ctor is called
- when an obj is initialized by another obj of same type
- when an obj is passed by value
- when obj is returned by value

struct Node {
  ...
  Node(Node other) : ... {} this will cause infinite recursion because other is passed by value.
}

struct Node{
  ...
  Node(int data) : data{data}, next{nullptr} {}
}
single-arg ctor => implicit conversion
Node n(4);
Node n = 4; // it works, implicit conversion from int to Node

string s = "Hello";
c++ string char*

int f(Node n);
f(4) // it works

Danger
- accidentally pass an int to a function expecting a Node
- siliently conversion
- compiler does not signal error

Advice: Don't do things that limit the compiler ability to help

struct Node{
  ...
  explicit Node(int data) : data{data}, next{nullptr} {}
}
Node n{4}; //OK
Node n = 4; //error
f(4); //error
f(Node{4}); //ok

when an obj is destroyed
- stock allocated: out of scope, program reaches '}' where it is created
- heap allocated: delete np
destructor is called, the destructor invokes destructor for all fields that are obj

Object destruction steps:
1. dtor body runs
2. fields dtors invoked in reverse order of declaration
3. space deallocated

Consider
int main() {
Node *np = new Node{1, new Node{2, new Node{3, nullptr}}};
}
problem occurs: np goes out of scope, ptr is destroyed, list *leaked*

delete np: first node is destroyed, node dtor runs(do nothing), the rest are still leaked

//write our own dtor
struct Node{
  ...
  ~Node(){} // this is the default dtor
  ~Node(){ delete next;} //since dtor runs body first, it will traverse the entire list as delete next would also call the dtor
}
delete nullptr is safe.

Copy assignment operator
Student s1{60,70,80};
Student s2 = s1
...
Student s3; //s3 is constructed here
...
s3 = s1; //copy assigment operator

struct Node{
  ...
  Node &operator=(const Node &other){
    //copy assignment operator
    data = other.data;
    next = other.next ? new Node(*other.next) : nullptr;
    return *this;
  } //this approach will only change the first original node's value, but for the rest, it will copy instead of altering value, which will cause memory leaks
}
struct Node{
  ...
  Node &operator=(const Node &other){
    //copy assignment operator
    data = other.data;
    delete next; // delete the old list (main difference between copy ctor and copy assignment operator)
    next = other.next ? new Node(*other.next) : nullptr;
    return *this;
  } //Still dangerous
}
Node n{1, new Node{2, new Node{3, nullptr}}};
n = n //self-assignment, undefined behaviour
Always make sure it behaves well in case of self-assignment
struct Node{
  ...
  Node &operator=(const Node &other){
    //copy assignment operator
    if(this == &other) return *this;
    data = other.data;
    delete next; // delete the old list (main difference between copy ctor and copy assignment operator)
    next = other.next ? new Node(*other.next) : nullptr;
    return *this;
  }
}
Alternative implementation
- library <utility> -> std::swap -> (a, b) => a = b and b = a
import <utility>;
struct Node {
  ...
  void swap(Node &other){
    std::swap(data, other.data);
    std::swap(next, other.next);  
  }
  Node &operator=(const &other){
    Node tmp = other; //deep copy -> temp is an independent list
    swap(tmp);
    return *this;
  }//tmp goes out of scope
}