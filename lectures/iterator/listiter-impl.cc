module list;

struct List::Node {
  int data;
  Node *next;

  Node (int data, Node *next): data{data}, next{next} {}
  ~Node() { delete next; }
};

List::Iterator::Iterator(Node *p): p{p} {}
int &List::Iterator::operator*() const { return p->data; }
List::Iterator &List::Iterator::operator++() {
  p = p -> next;
  return *this;
}
bool List::Iterator::operator==(const Iterator &other) const {
  return p == other.p; 
}
bool List::Iterator::operator!=(const Iterator &other) const {
  return !(*this == other); // calls List::Iterator::operator==(const Iterator &other)
}

List::Iterator List::begin() const { return Iterator{theList}; }
List::Iterator List::end() const { return Iterator{nullptr}; }

List::~List() { delete theList; }

void List::addToFront(int n) { theList = new Node{n, theList}; }

int List::ith(int i) const {
  Node *cur = theList;
  for (int j = 0; j < i && cur; ++j, cur = cur -> next);
  return cur->data;
}

