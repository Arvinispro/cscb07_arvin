import <compare>;
import <iostream>;
import <string>;

using namespace std;

// Big Two ordering, lowest to highest. Note that the 2 is the HIGHEST rank.
const string RANKS = "3456789TJQKA2";

// Big Two suit ordering, lowest to highest.
const string SUITS = "DCHS";  // Diamonds < Clubs < Hearts < Spades

struct Card {
  char rank;  // one of the characters in RANKS
  char suit;  // one of the characters in SUITS

  // Fill in the return type
  ___ operator<=>(const Card& other) const {
    // Fill in this operator overload
  }
};

// Given: reads a card written as two characters, e.g. "7H" or "AS"
istream& operator>>(istream& in, Card& c) {
  return in >> c.rank >> c.suit;
}

// Given: prints a card written as two characters, e.g. "7H" or "AS"
ostream& operator<<(ostream& out, const Card& c) {
  return out << c.rank << c.suit;
}

// Given: test harness. Do not modify.
int main() {
  Card hand[13];
  int size = 0;

  char c;
  while (cin >> c) {
    // Quit Program
    if (c == 'q') {
      break;
    } else if (c == 'd') {
      // Deal a card into the hand
      cin >> hand[size];
      ++size;
    } else if (c == 'p') {
      // Print the hand
      for (int i = 0; i < size; ++i) {
        cout << hand[i] << (i == size - 1 ? "" : " ");
      }
      cout << endl;
    } else if (c == 's') {
      // Sort the hand from lowest to highest (insertion sort, uses only <)
      for (int i = 1; i < size; ++i) {
        Card key = hand[i];
        int j = i - 1;
        while (j >= 0 && key < hand[j]) {
          hand[j + 1] = hand[j];
          --j;
        }
        hand[j + 1] = key;
      }
    }
  }
}
