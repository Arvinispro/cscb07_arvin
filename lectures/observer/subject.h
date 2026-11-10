#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"

class Subject {
  // Fixed-size array of observers; only the first numObservers entries are in use.
  inline static constexpr int maxObservers = 16;
  Observer *observers[maxObservers] = {};
  int numObservers = 0;

 public:
  Subject();
  void attach(Observer *o);   // ignored if the array is full
  void detach(Observer *o);
  void notifyObservers() const;
  virtual ~Subject()=0;
};

#endif
