import <iostream>;

struct Account {
  int id;               // 0 means "unused slot"
  double balance;
  Account(): id{0}, balance{0} {}
  Account(int id, double balance): id{id}, balance{balance} {}
  Account &operator+=(double amount) {
    balance += amount;
    return *this;
  }
};

std::ostream &operator<<(std::ostream &out, const Account &a) {
  return out << "Account " << a.id << ": $" << a.balance;
}

struct Bank {
  Account *accounts;    // array of Accounts
  int capacity;         // number of slots in the array
  int count;            // slots in use
  Bank(int cap);
  ~Bank();
  void grow();
  void open(int id, double balance);
  Account &operator[](int i) { return accounts[i]; }
  void printAll() const;
  int emptySlots() const;
};

Bank::Bank(int cap): accounts{new Account[cap]}, capacity{cap}, count{0} {}

Bank::~Bank() {
  delete [] accounts;
}

void Bank::grow() {
  Account *bigger = new Account[capacity * 2];
  for (int i = 0; i < count; ++i) bigger[i] = accounts[i];
  accounts = bigger;
  capacity *= 2;
}

void Bank::open(int id, double balance) {
  if (count == capacity) grow();
  accounts[count++] = Account{id, balance};
}

void Bank::printAll() const {
  for (int i = 0; i < count; ++i) std::cout << accounts[i] << '\n';
}

int Bank::emptySlots() const {
  int empty = 0;
  int i = capacity-1; //add -1
  while (i >= 0) { 
    if (accounts[i].id == 0) ++empty;
    --i;
  }
  return empty;
}

int main() {
  Bank b{3};
  b.open(101, 100);
  b.open(102, 50);
  b.open(103, 75);
  b.open(104, 20);     // the array is full here, so grow() runs
  b[1] += 25;
  b.printAll();
  std::cout << "free slots: " << b.emptySlots() << '\n';
}
