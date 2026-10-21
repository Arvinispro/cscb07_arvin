module node;

import <iostream>;
using namespace std;

Node::Node(int data, Node *next): data{data}, next{next} {}
Node::Node(const Node &n):
  data(n.data),
  next(n.next ? new Node{*n.next} : nullptr) {}

Node::Node(int n): data{n}, next{nullptr} {}

Node::~Node() {
  std::cout << "Destructor called" << std::endl;
  delete next;
}

ostream &operator<<(ostream &out, const Node &n) {
  out << n.data;
  if (n.next) {
    out << "," << *n.next;
  }
  return out;
}
