#include "QueueIterator.h"
#include "DigitalMedia.h"
QueueIterator::QueueIterator(Queue::Node *current, int &elapsed): current{current}. elapsed{elapsed}{}

// Time that will pass before the current item starts playing (0 at the front).
int QueueIterator::getElapsedTime() const{
  return this->elapsed;
}   

DigitalMedia * QueueIterator::operator*() const{
  return{this->current->m};
}

// Adds the duration of the current item to the elapsed time before moving the iterator
// to the next item. Any change to the queue invalidates the iterator.
QueueIterator QueueIterator::operator++(){
  this->elapsed += this->current->m->getDuration();
  return QueueIterator{this->current->next, this->elapsed};
}

bool QueueIterator::operator==( const QueueIterator & other ) const{
  return {this->current == other.current} 
}
bool QueueIterator::operator!=( const QueueIterator & other ) const{
  return {this->current != other.current}
}