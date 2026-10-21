Temporary object
Node && -> reference to a temp obj (rvalue)

If u don't define move ctor/assign operator
- Copying versions are used instead
- If u define them, they replace the copy when other is a temp object

Rule of 5 (If u need to write any of these, then u need to write all five)
- Copy ctor
- copy assign operator
- dtor
- move ctor
- move assign operator

You can't delete something in the stack, u can only delete things in heap

Invariant statement that must hold true upon which a class relies (Assumptions)

Encapsulation: 
- Objects are like black boxes(capsules)
- Implementation details are sealed away
- Client can manipulate objects via provided methods
- regain control

In general
- Fields should be private
- Methods should be public
struct -> default visibility is public
class -> default visibility is private

Try if we replace lst.end() by nullptr in the for loop in the released notes, does the program still work?