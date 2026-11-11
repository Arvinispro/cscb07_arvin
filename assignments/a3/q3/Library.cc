#include "Library.h"
#include "DigitalMedia.h"
#include "LibraryIterator.h"
#include "Song.h"
#include "Video.h"

Library::Library():head{nullptr}{}                  // Creates empty library.
Library::~Library(){
  if(this->head != nullptr){
    delete this->head->media;
    delete this->head->next;
  }
}                      // Destroys all items in library.
LibraryIterator Library::begin() const{
  return LibraryIterator{this->head};
}   // Iterator set to beginning of library contents.

LibraryIterator Library::end() const{
  Node *p = this->head;
  while(p != nullptr) p  = this->head->next;
  return LibraryIterator{p};
}     // Iterator set past end of library contents.

// Stores item, indexed by key. If key already exists outputs to stderr
// "key KKKK already exists in library" and item not stored (and is deleted).
void Library::add( DigitalMedia* m ){
  if(this->head==nullptr) {
    this->head = new Node{m, nullptr};
    return;
  }
  Node *last = this->head;
  Node *p = this->head->next;
  while(p != nullptr){
    if(p->media->getKey() == m->getKey()) {
      std::cerr << "key " << m->getKey() << " already exists in library" << std::endl;
      return;
    }
    if(p->media->getKey() > m->getKey()) break;

    last = last->next;
    p = p->next;
  }
  Node *newmedia = new Node{m, p};
  last -> next = newmedia;
  return;
}    

// Remove item and delete media if find key value else does nothing.
void Library::remove( const std::string& key ){
  if(this->head==nullptr) {
    return;
  }
  Node *last = this->head;
  Node *p = this->head->next;
  while(p != nullptr){
    if(p->media->getKey() == key) break;

    last = last->next;
    p = p->next;
  }
  last -> next = p -> next;
  delete p->media;
  delete p;
  return;
} 

// Returns pointer to item, or nullptr if not there.
DigitalMedia * Library::find( const std::string& key ) const{
  if(this->head==nullptr) {
    return nullptr;
  }
  Node *p = this->head;
  while(p != nullptr){
    if(p->media->getKey() == key) return p->media;

    p = p->next;
  }

  return nullptr;
}

// Returns modified output stream. Stream contains the header "Library:\n" and the library
// contents, ordered by key. Each object is output using the appropriate output operator
// for the underlying object type, one per line and starting with a tab character.
std::ostream & operator<<( std::ostream& out, const Library& library ){
  out << "Library:" << std::endl;
  for(LibraryIterator p=library.begin(); p != library.end(); ++p){
    out << "\t";
    (*p) -> print(out);
    out << std::endl;
  }
  return out;
}

// Returns modified input stream. Contents of library modified with information read in, 
// where the character 's' on a line specifies a Song is to be read next, while 'v'
// indicates that a Video is to be read in next. Reading continues until EOF is reached or an
// error occurs. If the item that follows cannot be read, nothing is added for it, reading
// stops, and the failbit of the stream is set. Outputs "invalid media type" to stderr followed
// by what type was read if doesn't get either 's' or 'v' (and then stops reading as well).
std::istream & operator>>( std::istream& in, Library& library ){
  std::string type;
  while(!in.eof() || in.fail()){
    std::getline(in, type);
    if(type=="s"){
      Song *s;
      in >> *s;
      library.add(s);
    }
    else if(type=="v"){
      Video *v;
      in >> *v;
      library.add(v);
    }
    else{
      std::cerr << "invalid media type" << std::endl;
      in.setstate(std::ios::failbit);
    }
  }
  return in;
}