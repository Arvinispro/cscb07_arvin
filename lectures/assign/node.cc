export module node;
import <iostream>;

export struct Node {
  int data;
  Node *next;

  explicit Node(int data, Node *next = nullptr);
  Node(const Node &n);
  ~Node();

  Node &operator=(const Node &other);
};

export std::ostream &operator<<(std::ostream &out, const Node &n);
