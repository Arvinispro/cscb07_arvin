module node;
import <iostream>;

using namespace std;

Node::Node(int data, Node *next = nullptr): data{data}, next{next} {}

Node::Node(const Node &n):
  data{n.data},
  next{n.next ? new Node{*n.next} : nullptr} {}

Node::~Node() {
  delete next;
}

Node &Node::operator=(const Node &other) {
  if (this == &other) return *this;
  data = other.data;
  Node *tmp = next;
  next = other.next ? new Node{*other.next} : nullptr;
  delete tmp;
  return *this;
}

ostream &operator<<(ostream &out, const Node &n) {
  out << n.data;
  if (n.next) {
    out << "," << *n.next;
  }
  return out;
}
