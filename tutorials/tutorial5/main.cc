import <iostream>;
import <string>;
using namespace std;

// ---------------------------------------------------------------------
// Pokemon: should be an abstract superclass
// ---------------------------------------------------------------------
class Pokemon {
  string nickname;  // private: do NOT add a getter for it

public:
  Pokemon(const string &nickname): nickname{nickname} {}

  // TODO: Pokemon are deleted through Pokemon pointers (see Party).
  ~Pokemon() {}

  // TODO: Pokemon must be an abstract class. Make these two methods
  // pure virtual (and remove the placeholder bodies).
  virtual string species() const { return ""; }
  virtual string moveName(int i) const { return ""; }

  string attack(int i) const { return nickname + " used " + moveName(i) + "!"; }

  // TODO: operator<< needs access to nickname. Declare it here.
};

// TODO: fix operator<<. It must print the nickname, a space, and the species
// in parentheses, e.g.  Sparky (Pikachu)
ostream &operator<<(ostream &out, const Pokemon &p) {
  return out << p.species();  
}

// ---------------------------------------------------------------------
// Concrete Pokemon. Each owns a heap array of its three moves.
// TODO: finish Pikachu first, then use it as a model for the other two.
// ---------------------------------------------------------------------
class Pikachu final: public Pokemon {
  string *moves;   // this Pikachu's three moves, stored on the heap

public:
  // TODO: pass the nickname to the superclass constructor, and make moves
  // point to a new heap array of 3 strings.
  Pikachu(const string &nickname): Pokemon{nickname}, moves{} {
    // TODO: fill in the three moves, in order (see the table in the
    // problem set).
  }

  // TODO: Pikachu owns the moves array. Free it here. Remember that it was
  // allocated as an array.
  ~Pikachu() {
  }

  // TODO: return this Pokemon's species as a string.
  string species() const override {
  }

  // TODO: return the name of move i.
  string moveName(int i) const override {
  }
};

// TODO: finish class Charmander, following the same pattern as Pikachu.
// Species "Charmander"; moves, in order: Ember, Scratch, Flamethrower.
// Remember: no one should ever subclass a concrete species.
class Charmander: public Pokemon {
public:
  Charmander(const string &nickname): Pokemon{nickname} {}
};

// TODO: finish class Squirtle, following the same pattern as Pikachu.
// Species "Squirtle"; moves, in order: Water Gun, Tackle, Bubble.
// Remember: no one should ever subclass a concrete species.
class Squirtle: public Pokemon {
public:
  Squirtle(const string &nickname): Pokemon{nickname} {}
};

// ---------------------------------------------------------------------
// Party: DO NOT MODIFY. Owns the Pokemon it points to; never copied.
// ---------------------------------------------------------------------
struct Party {
  Pokemon *pokemon[6];
  int size = 0;

  ~Party() {
    for (int i = 0; i < size; ++i) delete pokemon[i];
  }

  void add(Pokemon *p) { pokemon[size++] = p; }

  void release(int i) {
    delete pokemon[i];
    for (int j = i; j + 1 < size; ++j) pokemon[j] = pokemon[j + 1];
    --size;
  }
};

// ---------------------------------------------------------------------
// Test harness: DO NOT MODIFY.
// ---------------------------------------------------------------------
int main() {
  Party party;
  string cmd;
  while (cin >> cmd && cmd != "q") {
    if (cmd == "c") {
      string species, nickname;
      cin >> species >> nickname;
      if (species == "Pikachu") party.add(new Pikachu{nickname});
      else if (species == "Charmander") party.add(new Charmander{nickname});
      else if (species == "Squirtle") party.add(new Squirtle{nickname});
    } else if (cmd == "p") {
      cout << "Party of " << party.size << ":" << endl;
      for (int i = 0; i < party.size; ++i) {
        cout << i << ": " << *party.pokemon[i] << endl;
      }
    } else if (cmd == "m") {
      int i, j;
      cin >> i >> j;
      cout << party.pokemon[i]->attack(j) << endl;
    } else if (cmd == "r") {
      int i;
      cin >> i;
      cout << "Released " << *party.pokemon[i] << endl;
      party.release(i);
    }
  }
}
