import <iostream>;
using namespace std;

struct IntArray {
  int size; //number of elements the array currently holds
  int capacity; //number of elements the array could hold,
                //given current memory allocation to contents
  int *contents; //the integer array
};

IntArray readIntArray(){
  IntArray rsl;
  rsl.size = 0;
  rsl.capacity = 0;
  int a;
  while(cin >> a){
    if(rsl.size < rsl.capacity){
      rsl.contents[rsl.size] = a;
      rsl.size++;
    }
    else{
      if(rsl.capacity==0) rsl.capacity = 5; else rsl.capacity = rsl.capacity * 2;

      int *new_contents = new int[rsl.capacity];
      for(int i=0; i<rsl.size; i++){
        new_contents[i] = rsl.contents[i];
      }
      rsl.contents = new_contents;
      rsl.contents[rsl.size] = a;
      rsl.size++;
    }
  }
  cin.ignnore();
  return rsl;
}

void addToIntArray(IntArray& ia){
  int a;
  while(cin >> a){
    if(ia.size < ia.capacity){
      ia.contents[ia.size+1] = a;
      ia.size++;
    }
    else{
      if(ia.capacity==0) ia.capacity = 5; else ia.capacity = ia.capacity * 2;

      int *new_contents = new int[ia.capacity];
      for(int i=0; i<ia.size; i++){
        new_contents[i] = ia.contents[i];
      }
      ia.contents = new_contents;
      ia.contents[ia.size] = a;
      ia.size++;
    }
  }
  cin.ignnore();
}

void printIntArray(const IntArray& ia){
  for(int i=0; i < ia.size; i++){
    cout << ia.contents[i] << ' ';
  }
  cout << "\n" << "Capacity: " << ia.capacity << endl;
}


// Do not change this function!

int main() {  // Test harness for IntArray functions.
  bool done = false;
  IntArray a[4];
  a[0].contents = a[1].contents = a[2].contents = a[3].contents = nullptr;

  while(!done) {
    char c;
    char which;

    // Note:  prompt prints to stderr, so it should not occur in .out files
    cerr << "Command?" << endl;  // Valid commands:  ra, rb, rc, rd,
                                 //                  +a, +b, +c, +d,
                                 //                  pa, pb, pc, pd, 
                                 //                  q
    cin >> c;  // Reads r, +, p, or q
    if (cin.eof()) break;
    switch(c) {
      case 'r':
        cin >> which;  // Reads a, b, c, or d
        delete [] a[which-'a'].contents;
        a[which-'a'].contents = nullptr;
        a[which-'a'] = readIntArray();
        break;
      case '+':
        cin >> which;  // Reads a, b, c, or d
        addToIntArray(a[which-'a']);
        break;
      case 'p':
        cin >> which;  // Reads a, b, c, or d
        printIntArray(a[which-'a']);
        cout << "Capacity: " << a[which-'a'].capacity << endl;
        break;
      case 'q':
        done = true;
    }
  }

  for (int i = 0; i < 4; ++i) delete [] a[i].contents;
}

