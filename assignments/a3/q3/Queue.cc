#include "Queue.h"
#include "QueueIterator.h"
#include "DigitalMedia.h"

Queue::Queue(): front{nullptr}, back{nullptr}, totalSecond{0}, secondsPlayed{0} {}
Queue::~Queue(){
  // front->m = nullptr;
  // back->m = nullptr;
  delete front->next;
}           // the media items themselves are owned by the Library

void Queue::playNext( DigitalMedia * m ){
  Node *newmedia = new Node{m, this->front};
  this->totalSecond += m->getDuration();
  this->front = newmedia;
}  // adds m to the front of the queue
void Queue::playLast( DigitalMedia * m ){
  Node *newmedia = new Node{m, nullptr};
  this->totalSecond += m->getDuration();
  this->back->next = newmedia;
}  // adds m to the back of the queue

// "Plays" the item at the front of the queue: removes it from the queue, adds its
// duration to the number of seconds played, and returns it. Returns nullptr (and
// changes nothing) if the queue is empty.
DigitalMedia * Queue::play(){
  if(this->front==nullptr) return nullptr;
  Node *played = this->front;

  this->front->next = nullptr;
  delete this->front;
  this->front = played->next;

  this->secondsPlayed += played->m->getDuration();
  return played->m;
}

// Removes every occurrence of m from the queue. Does nothing if m isn't in the queue.
void Queue::remove( DigitalMedia * m ){
  if(this->front == nullptr) return;
  Node *last = this->front;
  Node *p = this->front->next;

  while(last->m == m){
    this->front = last -> next;
    last->next = nullptr;
    delete last;
    last = p;
    p = p->next;
  } //ensuring front is not matching

  while(p!=nullptr){
    if(p->m == m){
      last -> next = p->next;
      p->next = nullptr;
      delete p;
    }
    last = last->next;
    p = last->next;
  }
}

void Queue::reset(){
  this->secondsPlayed = 0;
}                       // resets the number of seconds played back to 0
int Queue::getTotalSeconds() const{
  return this->totalSecond;
}        // total duration of the items in the queue
int Queue::getSecondsPlayed() const{
  return this->secondsPlayed;
}       // total duration of the items played so far

QueueIterator Queue::begin() const{
  return QueueIterator{this->front, 0};
}        // Iterator set to the front of the queue.
QueueIterator Queue::end() const{
  return QueueIterator{this->back, this->getTotalSeconds()-this->back->m->getDuration()};
}  

// Returns modified output stream. Outputs each item on its own line, in queue order, as
// a tab, the position of the item (width 3, padded with '0'), ": ", the item's information,
// and " starts in N seconds" where N is the iterator's elapsed time at that item. The last
// line is "Total: N seconds", N being the total duration of the items in the queue.
std::ostream & operator<<( std::ostream & out, const Queue & q ){
  out << "Queue:" << std::endl;
  int p1=0, p10=0, p100=0;

  for(QueueIterator p=q.begin(); p != q.end(); ++p){
    out << "\t" << p100 << p10 << p1 << ": ";
    (*p) -> print(out);
    out << "starts in " << p.getElapsedTime() << " seconds" << std::endl;
    ++p1;
    if(p1 == 10){
      ++p10;
      p1=0;
    }
    if(p10 == 10){
      ++p100;
      p10=0;
    }
  }
  out << "Total: " << q.getTotalSeconds() << " seconds" << std::endl;
  return out;
}