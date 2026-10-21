export module node;
import <iostream>;

export struct Node {
  int data;
  Node *next;
  
  explicit Node(int n);
  Node(int data, Node *next);
  Node(const Node &n);

  ~Node();
};

export std::ostream &operator<<(std::ostream &out, const Node &n);
