#include "DigitalMedia.h"

// Sets key, title and duration information.
// If key.length() < 1 outputs to stderr: "key has length < 1".
// If title.length() < 1 outputs to stderr: "title has length < 1".
// If duration < 1 outputs to stderr: "duration < 1".
// (Checks are made in order listed.)
DigitalMedia::DigitalMedia( const std::string & key, const std::string & title, int duration ){
  if(key.length() < 1){ 
    std::cerr << "key has length < 1" << std::endl;
    return;
  }
  this -> key = key;
  if(title.length() < 1){ 
    std::cerr << "title has length < 1" << std::endl;
    return;
  }
  this -> title = title;
  if(duration < 1){ 
    std::cerr << "duration < 1" << std::endl;
    return;
  }
  this -> duration = duration;
}
DigitalMedia::~DigitalMedia(){}

// Concrete subclasses use this to invoke their output operator so that Library
// container can successfully print its contents using the iterator.
void DigitalMedia::print( std::ostream & out ) const {
  out << "(" << this->key << ", \"" << this -> title << "\", ";
}

const std::string & DigitalMedia::getKey() const{
  return this->key;
}
const std::string & DigitalMedia::getTitle() const{
  return this->title;
}
int DigitalMedia::getDuration() const{
  return this->duration;
}