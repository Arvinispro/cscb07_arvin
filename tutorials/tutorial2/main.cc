import <iostream>;
import <string>;

using namespace std;

struct Party {
  string pokemon[6];
  int size = 0;
};

// Fill in the return type and arguments
std::istream &operator>>(std::istream &cin, Party &poke) {
  // Fill in this operator overload
  std::string name;
  cin >> name;
  if(poke.size < 6){
    poke.pokemon[poke.size] = name;
    poke.size += 1;
  }
  return cin;
}

// Fill in the return type and arguments
std::ostream &operator<<(std::ostream &cout, Party &poke) {
  // Fill in this operator overload
  cout << "I have " << poke.size << " pokemon(s). They are:" << std::endl;
  if(poke.size>=2){
    for(int i = 0; i<poke.size-1; i++){
      cout << poke.pokemon[i] << ", ";
    }
    cout << poke.pokemon[poke.size-1] << std::endl;
  }
  else{
    for(int i = 0; i<poke.size-1; i++){
      cout << poke.pokemon[i];
    }
    cout << std::endl;
  }
  return cout;

}

// For operator-, argument and return types are given
Party operator-(const Party& fl, int index) {
  Party rsl;
  // Fill in this operator overload
  for(int i=0; i<fl.size; i++){
    if(i != index){
      rsl.pokemon[rsl.size] = fl.pokemon[i];
      rsl.size += 1;
    }
  }
  return rsl;
}

int main() {
  Party theList;
  char c;
  while (cin >> c) {
    // Quit Program
    if (c == 'q') {
      break;
    } else if (c == 'c') {
      // Add pokemon
      cin >> theList;
    } else if (c == 'p') {
      // Print pokemon
      cout << theList;
    } else if (c == 'r') {
      // Remove pokemon at index
      int index;
      cin >> index;
      theList = theList - index;
    }
  }
}
