import <iostream>;
import <string>;
import book;
import comic;

using namespace std;

int main() {
  Comic c{ "Robin Rescues Batman Twice", "Robin", 40, "Robin" };

  Book b = c;
  Book b2{ "Ancillary Justice", "Ann Leckie", 391 };
  Comic c2{ "War of the Gods", "George Perez", 1000, "Wonder Woman" };
  //c2 = b2; // error: no match for ‘operator=’ (operand types are ‘Comic@comic’ and ‘Book@book’)

  cout << "The comic book: " << c.getTitle() << "; " << c.getAuthor()
       << "; " << (c.isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << "The book: " << b.getTitle() << "; " << b.getAuthor()
       << "; " << (b.isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << endl << "Through pointers: " << endl;

  Comic *pc = new Comic{ "Spiderman Unabridged", "Peter Parker", 100, "Spiderman" };
  Book *pb = pc;

  cout << "The comic book ptr: " << pc->getTitle() << "; " << pc->getAuthor()
       << "; " << (pc->isItHeavy() ? "heavy" : "not heavy") << endl;

  cout << "The book ptr: " << pb->getTitle() << "; " << pb->getAuthor()
       << "; " << (pb->isItHeavy() ? "heavy" : "not heavy") << endl;

}
