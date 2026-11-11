#include "LibraryIterator.h"

LibraryIterator::LibraryIterator( Library::Node *current ): current{current}{}
DigitalMedia * LibraryIterator::operator*() const{
  return current->media;
}
LibraryIterator LibraryIterator::operator++(){
  return LibraryIterator{current->next};
}
bool LibraryIterator::operator==( const LibraryIterator& other ) const{
  return {this -> current == other.current};
}
bool LibraryIterator::operator!=( const LibraryIterator& other ) const{
  return {this -> current == other.current};
}