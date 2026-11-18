import <iostream>;
import <string>;
import <utility>;
using namespace std;

// ---------------------------------------------------------------------
// AbstractAccount: abstract superclass of all accounts.
// Everything here is provided, except the parts marked TODO (static members).
// ---------------------------------------------------------------------
class AbstractAccount {
  inline static constexpr int maxTx = 10;
  // TODO: declare two static fields here: one that hands out ids (the
  // first account gets id 1), and one that counts the AbstractAccount
  // objects that are currently alive.

  int id;
  string owner;
  int balance;
  int *history;      // heap array (size maxTx) of past transaction amounts
  int numTx;
  mutable int numQueries = 0;   // not part of the account's logical state

protected:
  // Protected: assignment through AbstractAccount pointers must not compile.
  AbstractAccount &operator=(const AbstractAccount &other);
  AbstractAccount &operator=(AbstractAccount &&other);

public:
  AbstractAccount(const string &owner, int initial);
  AbstractAccount(const AbstractAccount &other);
  AbstractAccount(AbstractAccount &&other);
  virtual ~AbstractAccount() = 0;   // the only pure virtual method

  void post(int amount) { balance += amount; history[numTx++] = amount; }
  int getBalance() const { ++numQueries; return balance; }
  int getQueries() const { return numQueries; }
  int getId() const { return id; }
  const string &getOwner() const { return owner; }
  int txCount() const { return numTx; }
  int tx(int i) const { return history[i]; }
  virtual string kind() const { return "Account"; }

  // TODO: this must return the number of AbstractAccount objects currently
  // alive (it is static: it belongs to the class, not to an account).
  static int howMany() { return 0; }
};

// TODO: a new account gets the next id, and must be counted.
AbstractAccount::AbstractAccount(const string &owner, int initial):
  id{0}, owner{owner}, balance{initial},
  history{new int[maxTx]}, numTx{0} {}

// A copy is a new account: it gets a new id, and its own history array.
AbstractAccount::AbstractAccount(const AbstractAccount &other):
  id{0}, owner{other.owner}, balance{other.balance},
  history{new int[maxTx]}, numTx{other.numTx} {
  for (int i = 0; i < numTx; ++i) history[i] = other.history[i];
  // TODO: the copy gets the next id, and must be counted.
}

// A move transfers the same account: the new object takes the id.
AbstractAccount::AbstractAccount(AbstractAccount &&other):
  id{other.id}, owner{std::move(other.owner)}, balance{other.balance},
  history{other.history}, numTx{other.numTx} {
  other.id = 0;
  other.history = nullptr;
  other.numTx = 0;
  // TODO: this new object must be counted. (It takes the source's id.)
}

// Assignment keeps this object's identity (id and numQueries).
AbstractAccount &AbstractAccount::operator=(const AbstractAccount &other) {
  if (this != &other) {
    int *copy = new int[maxTx];
    for (int i = 0; i < other.numTx; ++i) copy[i] = other.history[i];
    delete [] history;
    history = copy;
    owner = other.owner;
    balance = other.balance;
    numTx = other.numTx;
  }
  return *this;
}

AbstractAccount &AbstractAccount::operator=(AbstractAccount &&other) {
  if (this != &other) {
    delete [] history;
    owner = std::move(other.owner);
    balance = other.balance;
    history = other.history;
    numTx = other.numTx;
    other.id = 0;
    other.history = nullptr;
    other.numTx = 0;
  }
  return *this;
}

// A pure virtual destructor still needs a body: ~Chequing and ~Savings call it.
AbstractAccount::~AbstractAccount() {
  delete [] history;
  // TODO: this object is no longer alive.
}

// ---------------------------------------------------------------------
// Concrete accounts
// TODO: write the copy constructor, copy assignment, move constructor and
// move assignment of Chequing and of Savings. They must call the
// AbstractAccount versions.
// ---------------------------------------------------------------------
class Chequing final: public AbstractAccount {
  string branch;
  int cheques = 0;   // cheques written so far

public:
  Chequing(const string &owner, int initial, const string &branch):
    AbstractAccount{owner, initial}, branch{branch} {}

  // TODO: copy constructor. A copy starts with a fresh cheque book:
  // cheques stays 0.

  // TODO: copy assignment. Copy branch and cheques. Return *this.

  // TODO: move constructor. Careful: the argument is an lvalue. Move branch,
  // and transfer cheques.

  // TODO: move assignment. Move branch, and transfer cheques. Return *this.

  void writeCheque(int amount) { post(-amount); ++cheques; }

  string kind() const override {
    return "Chequing[" + branch + ", " + to_string(cheques) + "]";
  }
};

class Savings final: public AbstractAccount {
  int rate;   // interest rate, in percent

public:
  Savings(const string &owner, int initial, int rate):
    AbstractAccount{owner, initial}, rate{rate} {}

  // TODO: copy constructor, copy assignment, move constructor and move
  // assignment, in the same way as Chequing. All of them copy or transfer
  // rate (there is no special rule for Savings).

  string kind() const override { return "Savings[" + to_string(rate) + "%]"; }
};

// ---------------------------------------------------------------------
// Bank and test harness: DO NOT MODIFY.
// The bank owns the accounts it points to; it is never copied.
// ---------------------------------------------------------------------
enum Kind { CHEQUING, SAVINGS };

struct Bank {
  AbstractAccount *accts[10];
  Kind kinds[10];
  int size = 0;

  ~Bank() {
    for (int i = 0; i < size; ++i) delete accts[i];
  }

  void add(AbstractAccount *a, Kind k) {
    accts[size] = a;
    kinds[size] = k;
    ++size;
  }

  void remove(int i) {
    delete accts[i];
    for (int j = i; j + 1 < size; ++j) {
      accts[j] = accts[j + 1];
      kinds[j] = kinds[j + 1];
    }
    --size;
  }
};

void printAll(const Bank &bank) {
  cout << "Accounts: " << bank.size << endl;
  for (int i = 0; i < bank.size; ++i) {
    const AbstractAccount &a = *bank.accts[i];
    cout << i << ": ";
    if (a.getId() == 0) {
      cout << "(moved-from)" << endl;
    } else {
      cout << "#" << a.getId() << " " << a.kind() << " \"" << a.getOwner()
           << "\" " << a.getBalance() << " [";
      for (int t = 0; t < a.txCount(); ++t) {
        if (t > 0) cout << " ";
        cout << a.tx(t);
      }
      cout << "]" << endl;
    }
  }
}

// Copying/moving through a base pointer is a topic for later in the course,
// so the harness uses the kind it recorded to pick the concrete type.
int main() {
  Bank bank;
  string cmd;
  while (cin >> cmd && cmd != "q") {
    if (cmd == "o") {
      string type, owner, extra;
      int initial;
      cin >> type >> owner >> initial >> extra;
      if (type == "Chequing") {
        bank.add(new Chequing{owner, initial, extra}, CHEQUING);
      } else {
        bank.add(new Savings{owner, initial, stoi(extra)}, SAVINGS);
      }
    } else if (cmd == "d") {
      int i, amount;
      cin >> i >> amount;
      bank.accts[i]->post(amount);
    } else if (cmd == "w") {
      int i, amount;
      cin >> i >> amount;
      static_cast<Chequing *>(bank.accts[i])->writeCheque(amount);
    } else if (cmd == "b") {
      int i;
      cin >> i;
      const AbstractAccount &a = *bank.accts[i];
      cout << "Balance: " << a.getBalance() << endl;
    } else if (cmd == "n") {
      int i;
      cin >> i;
      cout << "Queries: " << bank.accts[i]->getQueries() << endl;
    } else if (cmd == "p") {
      printAll(bank);
    } else if (cmd == "s") {
      cout << "Live accounts: " << AbstractAccount::howMany() << endl;
    } else if (cmd == "c") {
      int i;
      cin >> i;
      if (bank.kinds[i] == CHEQUING) {
        bank.add(new Chequing{static_cast<const Chequing &>(*bank.accts[i])},
                 CHEQUING);
      } else {
        bank.add(new Savings{static_cast<const Savings &>(*bank.accts[i])},
                 SAVINGS);
      }
    } else if (cmd == "a") {
      int i, j;
      cin >> i >> j;
      if (bank.kinds[i] == CHEQUING) {
        static_cast<Chequing &>(*bank.accts[i]) =
          static_cast<const Chequing &>(*bank.accts[j]);
      } else {
        static_cast<Savings &>(*bank.accts[i]) =
          static_cast<const Savings &>(*bank.accts[j]);
      }
    } else if (cmd == "m") {
      int i;
      cin >> i;
      if (bank.kinds[i] == CHEQUING) {
        bank.add(new Chequing{std::move(static_cast<Chequing &>(*bank.accts[i]))},
                 CHEQUING);
      } else {
        bank.add(new Savings{std::move(static_cast<Savings &>(*bank.accts[i]))},
                 SAVINGS);
      }
    } else if (cmd == "ma") {
      int i, j;
      cin >> i >> j;
      if (bank.kinds[i] == CHEQUING) {
        static_cast<Chequing &>(*bank.accts[i]) =
          std::move(static_cast<Chequing &>(*bank.accts[j]));
      } else {
        static_cast<Savings &>(*bank.accts[i]) =
          std::move(static_cast<Savings &>(*bank.accts[j]));
      }
    } else if (cmd == "r") {
      int i;
      cin >> i;
      bank.remove(i);
    }
  }
}
