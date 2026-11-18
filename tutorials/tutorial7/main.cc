#include <iostream>
#include <string>
#include <map>
using namespace std;

// ---------------------------------------------------------------------
// Counter<T>: counts how many times each item has been added.
// ---------------------------------------------------------------------
// TODO: Counter must be a class template with one type parameter, named T:
// the type of the items that are counted. Write the template header before
// "class Counter".
class Counter {
  // TODO: declare the member "counts": a map from an item (of type T) to the
  // number of times it was added (an int).

public:
  // TODO: add one occurrence of item. Declare the parameter "item": its type
  // is T, passed by const reference. Think about what happens the first time
  // an item is added: a map's operator[] inserts a missing key with a
  // default-constructed value.
  void add(/* TODO: parameter */) {
  }

  // TODO: return the number of times item was added (0 if never, or if it was
  // removed). Declare the parameter "item" in the same way as for add. This is
  // a const method, and it must NOT insert item into the map. Hint: operator[]
  // is not available on a const map. Use find (or count) instead.
  int count(/* TODO: parameter */) const {
    return 0;
  }

  // TODO: forget item completely. Declare the parameter "item" in the same
  // way as for add. Do nothing if item is not present.
  void remove(/* TODO: parameter */) {
  }

  // TODO: forget every item that was added fewer than n times.
  // Be careful when you erase inside a loop over the map: after erase, the
  // iterator you erased is invalid. Erase returns an iterator to use instead.
  void removeBelow(int n) {
  }

  // TODO: print "Distinct: " and the number of distinct items, then one line
  // "item: count" for each item, in sorted order. Use a range-based for loop
  // with a structured binding to get the item and its count.
  void print() const {
  }
};

// ---------------------------------------------------------------------
// Test harness: DO NOT MODIFY.
// ---------------------------------------------------------------------
template <typename T> void run() {
  Counter<T> counter;
  string cmd;
  while (cin >> cmd && cmd != "q") {
    if (cmd == "a") {
      T item;
      cin >> item;
      counter.add(item);
    } else if (cmd == "c") {
      T item;
      cin >> item;
      cout << "Count of " << item << ": " << counter.count(item) << endl;
    } else if (cmd == "r") {
      T item;
      cin >> item;
      counter.remove(item);
    } else if (cmd == "b") {
      int n;
      cin >> n;
      counter.removeBelow(n);
    } else if (cmd == "p") {
      counter.print();
    }
  }
}

int main() {
  string type;
  cin >> type;   // "int" or "string": the type of the items
  if (type == "int") run<int>();
  else run<string>();
}
