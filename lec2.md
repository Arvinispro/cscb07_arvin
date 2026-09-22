In C
int *p = malloc(... *sizeof(int));
...
free(p)

In C++

Node *np = new Node;
    (stack)   (heap)
...
delete np;

All local variables reside on the *stack*, and variables are deallocated when they go out of scope (ie. function finishes) 
Allocated memory reside on *heap*, and they remains allocated until *delete* is called

Problem, Memory leak: When we forgot to delete the allocated memory in heap after the local variable is popped from stack.

# Arrays

Node *nodeArray = new Node[10];
...
delete [] nodeArray;

Takeaway:
    Memory allocated with new -> deallocated with *delete*
    Memory allocated with new...[] -> deallocated with *delete []*
Mixing them would lead to undefined behaviour


Given a function validDiscounT(string)
we can use ./validDiscounT < file1.in to let the function read the file1.in content and put it into the input and start running

we can use ./validDiscounT < file1.in > file1.out to save the output into a file name file1.out

Testings:
	Types of testing is determined by the knoweldge of program implementation
	
	Black box: No idea 
	White box: Full knowledge
	Grey box: Partial 
	
	## Black box
	-Functionality specification
	-Try out whole bunch of inputs and the expected output
	## White box
	-Branches covered, try to cover all the conditions
	-Testing specific component in the code since u can see them
	-Hardcide backdoor: this is specific code left by developer for testing ie. if(input == 'ADMIN99'){...}

Advice:
	-Start with Black box testing -> supplement with the white box testing 
	-Cover various classes of inputs (numeric ranges, positive vs negative...)
	-Boundaries of valid ranges (edge cases)
	-Intuition/experience - guess likely errors
	-Extreme cases (within reason)
	For white box testing:
		-Execute all logical paths through the program
		-Make sure that every function runs (Remove dead code that is never run)
	DON'T TEST INVALID INPUT, unless a behaviour has been specified
	- if input is invalid -> undefined behaviour -> no test case is meaningful
	
Regression testing
	-Make sure the changes don't break the test results
	-Rerun test cases, testing scripts
	-Always add new tests, never subtract

Classes
- A structure type that contains functions
- C++ has a a 'class' keyword
- Member function = methods, Member data = fields

Object
- An instance of class


:: -> scope resolution operator
ie. C::f = method f in the context of class calculate
used like '.', s.grade() but the LHS is a *class* (or a namespace)

every method in a class contains a parameter *this* == &instance, same as the self in python. 'this' is a pointer to the object on which the method is called

Methods can be written in the class
- Done for brevity
- You should put ur function implementation in a seperate file.