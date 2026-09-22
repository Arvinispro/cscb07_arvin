// example of memory leak
void foo(){
  Node *np = new Node;
  ...
}
// example of NO memory leak
void foo(){
  Node *np = new Node;
  ...
  delete np
}

//example of a class
struct Student{
	int assns, test, final;
	float grade(); //calculate final grade
}
float Student::grade(){
	return assns * 0.4 + test * 0.2 + final * 0.4;
}
Student s{60, 70, 90};
cout << s.grade() << endl;

//example of using this
struct Student{
	int assns, test, final;
	float grade(){
		return this->assns * 0.4 + this->test * 0.2 + this->final * 0.4;
	}; //calculate final grade
}