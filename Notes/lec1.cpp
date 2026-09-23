#include <iostream> // This is the C++ I/O

int main()
{
	std::cout << "Hello World" << std::endl;
	std::count << "H";
	std::count << "i";
	std::count << "!";
	
	endl; // This is end of line, and it also flushes output buffer

	using namespace std; // omit "std::" prefix

	// constant
	const int maxFrade = 100 // must be initialized

			struct Node
	{
		int data;
		/*struct*/ Node *next;
	};
	// Bad example, not gonna work
	struct Node
	{
		int data;
		Node next; // because node declaration not concluded yet
	};

	Node n{5, nullptr}; // Null => NO

	const Node n2 = n;

	// Parameter passing
	void inc(int n) { ++n; }
	int x = 5;
	inc(x);
	cout << x << endl; // 5

	// incrementing
	int x = 5;
	int y = ++x; // y=6, x=6, increment x first and assign to y
	int z = x++; // z=5, x=6, assign to z first, and increment x

	void inc(int *n) { ++*n; }
	int x = 5;
	inc(&x); // x's address is passed into inc, inc changes the data at the provided address

	// Reference
	int y = 10;
	int &z = y; //& makes z a 'reference' variable. Now z and y are both refering to the same data with different name. Using z=20 would make y=20 as well. z and y are called 'alias' which is the same variable in memory with different names

	int *p = &z // taking the address of z would give the address of y because they are referring to the same location

	int y = 10;
	int *z = &y; // Although changing z would also change y. But now z and y are two different variables where z stores the address and y holds the value.

	//& can mean reference or address-of
	something = &a								 //& occurs in an experssion, it is the address-of
	int &x = something //& occurs as a part of a type, it is the reference

	/* What can't u do with refereces?
		Cannot leave them uninitialized, e.g. int &x;

		It must be initialized to "something with an address"(lvalue) e.g. int &x = 3 (NO), int &x = y+z (NO)

		Cannot create pointer to a ref. e.g. int &*x;
		But ref to pointer is ok e.g. int *&x;

		Cannot create a ref to a ref, e.g. int &&r -> this means something else

		Cannot create an array of references, e.g. int &r[3] = {a,b,c}; (NO)
	*/

	/*What can u do with references?
		Pass as function parameter: Pass-by-reference
		void inc (int &n){
			//constant ptr to the argument
			//changes to n affect the original argument
			++n; //No pointer reference
		}
		int x=5;
		inc(x);
		cout << x << endl; //6
	*/
	return 0; // This is assumed in C++
};